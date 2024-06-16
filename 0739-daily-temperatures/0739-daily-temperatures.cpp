class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n);
        for(int i = 0; i<n;i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                res[st.top()] = i- st.top();
                st.pop();
            } 
            st.push(i);
        }

        return res;
    }
};