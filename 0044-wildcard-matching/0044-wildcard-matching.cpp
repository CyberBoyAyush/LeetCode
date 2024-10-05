class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        

        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

        // Base Case -> if(i==0 && j==0)
        dp[0][0] = true;

        // Base Case -> // if s gets exhausted and p is still left(i==0 && j>0)
        for(int j = 1; j<=m ; j++){
            bool flag = true;
            // all left chars in p shold be *
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        // Base Case -> if(j == 0 && i>0)
        for(int i = 1; i<=n ; i++){
            dp[i][0] = false;
        }

        // filling the rest of table
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m ;j++){
               // matched or ? case
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    // go less in both strings
                    dp[i][j] = dp[i-1][j-1];
                }

                // check for * case
                else if(p[j-1] == '*'){
                    // we take and not take *
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

                else{
                    dp[i][j] = false;
                } 
            }
        }

        return dp[n][m];
    }
};