class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        for(auto ch : s){
            mpp[ch]++;
        }

        for(auto ch:t){
            mpp[ch]--;
        }

        for(auto ch: mpp){
            if(ch.second!=0){
                return false;
            }                    
        }
        return true;
    }
};