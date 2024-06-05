class Solution {
public:
    string reorganizeString(string str) {
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