class Solution {
public:
    void computeLPS(string pat, vector<int> &LPS, int M){
        int len = 0;
        LPS[0] = 0;
        
        int i = 1;
        
        while(i<M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            
            else{
                if(len!=0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(),0);

        computeLPS(temp,LPS,temp.length());

        int longestLPS = LPS[temp.length() - 1];

        string culprit = rev.substr(0,s.length() - longestLPS);

        return culprit + s;
    }
};