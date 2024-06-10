class Solution {
public:
    void reverseString(vector<char>& arr) {
        // Two pointer -> best
        // int s = 0;
        // int e = arr.size()-1;
        // while(s<e){
        //     swap(arr[s++],arr[e--]);
        // }

        // using stack
        stack<int> st;
        for(auto it:arr){
            st.push(it);
        }

        int i = 0;
        while(!st.empty()){
            arr[i] = st.top();
            st.pop();
            i++;
        }
    }
};