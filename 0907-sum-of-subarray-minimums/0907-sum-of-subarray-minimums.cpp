class Solution {
public:
// In one of NSL or NSR weee have to check for equal so that we can eliminate duplciate subarrays to form
// finding NSL
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;

        for(int i = 0; i<n ;i++){
            if(st.empty()) res[i] = -1;

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        return res;
    }
// finding NSR
    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            if(st.empty()) res[i] = n;

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? n:st.top();
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);

        long long sum = 0;
        int M = 1e9 + 7;

        for(int i = 0; i<n ; i++){
            long long ls = i - NSL[i]; //distance to nearest smaller to left from i
            long long rs = NSR[i] - i; //distance to nearest smaller to right from i

            long long totalpos = ls*rs;

            long long totalSum = arr[i] * totalpos;

            sum = (sum + totalSum) % M; // given in ques
        }
        return sum;
    }
};