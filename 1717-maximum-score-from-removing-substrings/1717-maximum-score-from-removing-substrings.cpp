// class Solution {
// public:
//     string removeSubstr(string &s,string &match){
//         // stack for operations
//         stack<int> st;

//         for(auto ch : s){
//             if(!st.empty() && ch == match[1] && st.top()==match[0]){
//                 st.pop();
//             }
//             else{
//                 st.push(ch);
//             }
//         }

//         // creating remaning str
//         string rem;
//         while(!st.empty()){
//             rem.push_back(st.top());
//             st.pop();
//         }
//         reverse(rem.begin(),rem.end()); // bcz stack reversed it so we have to reverse it agin to get the original string
//         return rem;
//     }
//     int maximumGain(string s, int x, int y) {
//         int n = s.length();
//         int score = 0; // final ans

//         // sub sctring creation
//         string maxStr = (x>y) ? "ab" : "ba";
//         string minStr = (x<y) ? "ab" : "ba";
//         // First Pass -> for maxstring
//         string temp_first     = removeSubstr(s, maxStr);
//         int removedPairsCount = (n - temp_first.length()) / 2;
//         score                += removedPairsCount * max(x, y);

//         // second pass -> for minstr
//         string temp_second = removeSubstr(temp_first, minStr);
//         removedPairsCount  = (temp_first.length() - temp_second.length()) / 2;
//         score             += removedPairsCount * min(x, y);

//         return score;
//     }
// };

//Approach-2 (Without Stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n     = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int L                 = temp_first.length();
        int removedPairsCount = (n - L) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (L - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

    string removeSubstring(string& inputString, string& matchStr) {
        int j = 0;

        for (int i = 0; i < inputString.size(); i++) {
            inputString[j++] = inputString[i];

            if (j > 1 &&
                inputString[j - 2] == matchStr[0] &&
                inputString[j - 1] == matchStr[1]) {
                j -= 2;
            }
        }

        inputString.erase(inputString.begin() + j, inputString.end());

        return inputString;
    }
};