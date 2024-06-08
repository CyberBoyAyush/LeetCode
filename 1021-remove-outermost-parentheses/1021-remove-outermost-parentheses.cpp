class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int cnt = 0; // counter
        string ans; 

        for(int i = 0; i<n; i++){
            if(s[i]== ')')
                cnt--;

            if(cnt!=0)
                ans+=s[i];

            if(s[i] == '(')
                cnt++;    
        }
        return ans;
    }
};