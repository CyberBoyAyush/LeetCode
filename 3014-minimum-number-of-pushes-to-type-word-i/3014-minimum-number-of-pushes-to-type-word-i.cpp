// Approach 1 -> Using map and mapping it
// class Solution {
// public:
//     int minimumPushes(string word) {
//         int result = 0;

//         unordered_map<int,int> mpp;

//         int assign_key = 2;
//         for(char &ch:word){
//             if(assign_key > 9){
//                 assign_key = 2;
//             }
            
//             mpp[assign_key]++;
//             result += mpp[assign_key];
//             assign_key++;
//         }

//         return result;
//     }
// };

// Appraoch 2 -> Much cleaner code (Also work for repeating char)
class Solution {
public:
    int minimumPushes(string word) {
        // Taking map or a vector for storing the frequency
        vector<int> mpp(26,0);

        // calculating the frequency
        for(char &ch:word){
            mpp[ch - 'a']++;
        }

        // sorting it accoirding to descending order of frequency
        sort(mpp.begin(),mpp.end(),greater<int>());

        int result = 0;

        for(int i = 0 ; i<26 ; i++){
            int freq = mpp[i];
            int pressNeeded = i/8 + 1;

            result += freq * pressNeeded;
        }

        return result;
    }
};