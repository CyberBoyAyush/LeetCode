class Solution {
public:
    string reorganizeString(string str) {
    //    int hash[26] = {0};
    //    int n = s.length();

    //     //storing freq
    //    for(int i =0; i<n; i++){
    //     hash[s[i] - 'a']++;
    //    }

    //     //find most freq char
    //     char maxFreqChar;
    //     int maxFreq = INT_MIN;
    //     for(int i = 0; i<26; i++){
    //         if(hash[i]>maxFreq){
    //             maxFreq = hash[i];
    //             maxFreqChar = i + 'a';
    //         }
    //     }

    //     //now placing max freq char adjacently
    //     int index = 0;
    //     while(maxFreq>0 && index<n){
    //         s[index] = maxFreqChar;
    //         maxFreq--;
    //         index+=2; //skips by 2
    //     }

    //     if(maxFreq != 0){
    //         return "";
    //     }

    //     //now rmeoving freq of most frequent char
    //     hash[maxFreqChar - 'a'] = 0;

    //     // placing rest of char
    //     for(int i = 0; i<n;i++){
    //         while(hash[i]>0){
    //             index = index>=n ? 1:index;
    //             s[index] = i + 'a';
    //             index+=2;
    //             hash[i]--;
                
    //         }
    //     }
    //     return s;
    int hash[26] = {0};
        for (char c : str) {
            hash[c - 'a']++;
        }

        // Find the character with the maximum frequency
        int max = 0, letter = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > max) {
                max = hash[i];
                letter = i;
            }
        }

        // If the maximum frequency is more than half the length of the string + 1, return ""
        if (max > (str.length() + 1) / 2) {
            return "";
        }

        // Result array to store the reorganized characters
        string res(str.length(), ' ');

        // Fill all even places with the most frequent character
        int idx = 0;
        while (hash[letter]-- > 0) {
            res[idx] = 'a' + letter;
            idx += 2;
        }

        // Fill the remaining characters
        for (int i = 0; i < 26; i++) {
            while (hash[i]-- > 0) {
                if (idx >= res.length()) {
                    idx = 1;
                }
                res[idx] = 'a' + i;
                idx += 2;
            }
        }

        return res;
    }
};