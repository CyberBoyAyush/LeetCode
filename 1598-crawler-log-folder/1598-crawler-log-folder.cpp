// Simulation TC - O(N) SC - O(1)
// class Solution {
// public:
//     int minOperations(vector<string>& logs) {
//       int depth = 0;

//       for(auto log:logs){
//         if(log=="../"){
//             depth--;
//             if(depth<0) depth = 0;
//         }
//         else if(log == "./") continue;
//         else{
//             depth++;
//         }
//       }
//       return depth;  
//     }
// };

// Using stack TC - O(N) SC - O(N)
class Solution {
public:
    int minOperations(vector<string>& logs){
        stack<string> st;

        for(auto log : logs){
            if(log=="../"){
                if(!st.empty()) st.pop();
            }
            else if(log!="./"){
                st.push(log);
            }
        }
        return st.size();
    }
};