class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp; // stores string and count

        stringstream ss1(s1); // this part extract words from string
        string token = ""; // empty string for storing words

        while(ss1 >> token){ // this process extracts words 
            mp[token]++; // pushing count in map
        }

        stringstream ss2(s2);
        while(ss2 >> token){
            mp[token]++;
        }

        vector<string> res;
        for(auto &s:mp){
            if(s.second == 1){
                res.push_back(s.first);
            }
        }
        return res;
    }
};