class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);

        //edge case
        if(numRows==1){
            return s;
        }

        int i = 0;
        bool flag = false;
        for(auto ch:s){
            ans[i] += ch;
            if(i==0 || i == numRows-1){
                // invert the flag(change it)
                flag = !flag;
            }
            if(flag==true){
                i++;
            }
            else{
                i--;
            }
        }
        // pushing all chars row wise
        string res;
        for(auto str:ans){
            res += str;
        }
        return res;
    }
};