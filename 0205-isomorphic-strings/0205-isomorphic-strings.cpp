class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map1[256] = {0};
        int map2[256] = {0};

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            // Mapping from s to t
            if (map1[ch1] != 0 && map1[ch1] != ch2) {
                return false; // Inconsistent mapping, strings are not isomorphic
            }
            map1[ch1] = ch2;

            // Mapping from t to s
            if (map2[ch2] != 0 && map2[ch2] != ch1) {
                return false; // Inconsistent mapping, strings are not isomorphic
            }
            map2[ch2] = ch1;
        }

        return true; // All mappings are consistent, strings are isomorphic
    }
};