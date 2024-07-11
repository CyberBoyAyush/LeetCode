// Bruteforce TC - O(n^2)

// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<int> lastSkipLength; // storing the length of string before the opening bracket

//         string res = "";

//         for(auto c:s){
//             if(c == '('){
//                 lastSkipLength.push(res.length());
//             }
//             else if(c == ')'){
//                 int l = lastSkipLength.top();
//                 lastSkipLength.pop();
//                 //reverse
//                 reverse(res.begin()+l , res.end());
//             }
//             else{
//                 res.push_back(c);
//             }
//         }
//         return res;
//     }
// };

// Optimal TC - O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> bracPos;
        vector<int> door(n);

        // create mapping
        for(int i = 0; i<n; i++){
            if(s[i]=='('){
                bracPos.push(i);
            }
            else if(s[i]==')'){
                int j = bracPos.top();
                bracPos.pop();
                door[i] = j;
                door[j] = i; // two way mapping
            }
        }

        // craeting res string
        string res;
        int flag = 1; // direction 

        for(int i = 0; i<n ;i += flag){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                flag = -flag;
            }
            else{
                res += s[i];
            }
        }

        return res;
    }
};