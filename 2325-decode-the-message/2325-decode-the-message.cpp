class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> mpp;
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        mpp[' '] = ' ';
        int index = 0;
        for(int i = 0; i<key.length();i++){
            if(mpp[key[i]]==0){
                mpp[key[i]] = alphabets[index];
                index++;
            }
        }

        string ans;
        int ndex = 0;
        for(int i = 0; i<message.length();i++){
            ans.push_back(mpp[message[i]]);

        }
        return ans;
    }
};