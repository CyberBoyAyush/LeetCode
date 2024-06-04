class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; //edge case

        // Sort the array of strings
        sort(strs.begin(), strs.end());

        // Compare the first and the last strings in the sorted array
        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        int i = 0;
        // Find the common prefix between the first and last strings
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            ++i;
        }
        
        // Return the common prefix
        return first.substr(0, i);
    }
};