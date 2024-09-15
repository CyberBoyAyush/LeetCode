class Solution {
public:
    int findTheLongestSubstring(string s) {
        // map for storing the state and which index it was on last time
        unordered_map<int,int> mpp;

        int mask = 0; // 00000

        mpp[mask] = -1;

        int result = 0; // stores the length

        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a'){
                mask = (mask ^ (1<<0));
            }
            else if(s[i] == 'e'){
                mask = (mask ^ (1<<1));
            }
            else if(s[i] == 'i'){
                mask = (mask ^ (1<<2));
            }
            else if(s[i] == 'o'){
                mask = (mask ^ (1<<3));
            }
            else if(s[i] == 'u'){
                mask = (mask ^ (1<<4));
            }

            // comparing it to map
            if(mpp.find(mask) != mpp.end()){
                result = max(result, i - mpp[mask]);
            }
            else{
                // update it in map
                mpp[mask] = i;
            }
        }
        return result;
    }
};