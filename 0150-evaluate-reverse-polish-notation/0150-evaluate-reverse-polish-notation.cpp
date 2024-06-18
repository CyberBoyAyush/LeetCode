class Solution {
public:
    int operate(int a , int b, string token){
        if(token=="+")
            return a+b;
        else if(token == "-")
            return a-b;
        else if(token == "*")
            return (long) a * (long) b; // can overflow
        else
            return a/b;

        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result = operate(a,b,token);
                st.push(result);
            }
            else{
                st.push(stoi(token)); // we convert in into integer
            }
        }
        return st.top();
    }
};