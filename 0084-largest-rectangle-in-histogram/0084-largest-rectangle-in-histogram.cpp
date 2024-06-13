class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 3 Pass Solution - Good But we can do in 1 Pass
        // int n = heights.size();
        // vector<int> right(n);
        // vector<int> left(n);
        // stack<int> st;

        // // NSR
        // for(int i = 0; i<n ;i++){
        //     while(!st.empty() && heights[st.top()]>heights[i]){
        //         right[st.top()] = i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }

        // // empty stack and pushing extreme values in it
        // while(!st.empty()){
        //     right[st.top()] = n;
        //     st.pop();
        // }

        // //NSL
        // for(int i = n - 1; i >= 0; i--){
        //      while(!st.empty() && heights[st.top()] > heights[i]){
        //         left[st.top()] = i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }

        // // empty stack and pushing extreme values in it
        // while(!st.empty()){
        //     left[st.top()] = -1;
        //     st.pop();
        // }

        // //calculating area
        // int ans = 0;
        // for(int i = 0; i<n; i++){
        //     int area = heights[i] * (right[i] - left[i] -1);
        //     ans = max(ans,area);
        // }
        // return ans;

        // 1 Pass SOlution
        int ans = 0; 
        int index;
        int n = heights.size();
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                index = st.top();
                st.pop();

                if(!st.empty()){
                    ans = max(ans,heights[index] * (i-st.top()-1));
                } 
                else{
                    ans = max(ans,heights[index]*i);
                }
            }
            st.push(i);
        }

        // for elements in stack
        while(!st.empty()){
            index = st.top();
                st.pop();

                if(!st.empty()){
                    ans = max(ans,heights[index] * (n-st.top()-1));
                } 
                else{
                    ans = max(ans,heights[index]*n);
                }
        }
        return ans;

    }
};