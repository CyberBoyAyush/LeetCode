class Solution {
public:
    bool isPalindrome(string&s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // bruteforce
        int n = s.length();

        string ans = "";
        for(int i = 0; i<n;i++){
            for(int j = i; j<n;j++){
                if(isPalindrome(s,i,j)){
                    string t = s.substr(i,j-i+1);
                    ans = t.size() > ans.size() ? t:ans;
                }
            }
        }
        return ans;
    }
};