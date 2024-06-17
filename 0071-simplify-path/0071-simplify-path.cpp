class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        stack<string> st;

        while(getline(ss,token,'/')){
            if(token == "" || token == "."){
                continue;
            }
            if(token != ".."){
                st.push(token);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string res = "";
        if(st.empty()){
            return "/"; //--> stack empty and path is on root
        }
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};