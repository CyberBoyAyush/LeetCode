class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // creation of mask
        int mask = 0;

        for(auto ch:allowed){
            mask |= (1 << (ch - 'a'));
        }

        int count = 0;

        for(auto word : words){
            bool flag = true;

            for(auto ch : word){
                if(((mask >> (ch - 'a')) & 1) == 0){
                    flag = false;
                    break;
                }
            }

            if(flag){
                count++;
            }
        }

        return count;
    }
};