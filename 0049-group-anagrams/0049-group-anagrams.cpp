class Solution {
public:
    string generate(string &s){
        int count[26] = {0};

        // mapping
        for(auto ch:s){
            count[ch - 'a']++;
        }

        string new_str;
        //retreving new str
        for(int i=0; i<26;i++){
            if(count[i]>0){
                new_str += string(count[i], i + 'a');
            }
        }
        return new_str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Using sorting TC - k(nlogn)
        // unordered_map<string, vector<string>> mpp;

        // for(auto s : strs){
        //     string t = s;
        //     sort(t.begin(),t.end());
        //     mpp[t].push_back(s);
        // }
        // vector<vector<string>> anagrams;
        // for(auto m : mpp){
        //     anagrams.push_back(m.second);
        // }

        // return anagrams;

        //Better approach using hashing arr
        unordered_map<string,vector<string>> mpp;

        for(auto s:strs){
            string t = generate(s);
            mpp[t].push_back(s);
        }  

        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};