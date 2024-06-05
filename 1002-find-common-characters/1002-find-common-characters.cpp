class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize the frequency array for the minimum frequency of each character
        vector<int> minFreq(26, INT_MAX);
        
        // Iterate over each string in the list
        for (auto word : words) {
            vector<int> freq(26, 0); // Frequency array for the current word
            // Count the frequency of each character in the current word
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            // Update the minimum frequency array with the minimum counts
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        
        // Construct the result based on the final minimum frequency array
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minFreq[i]; j++) {
                result.push_back(string(1, 'a' + i));
            }
        }
        
        return result;
    }
};