class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i = 0; i<s.length();i++){
            if(s[i] == '*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};