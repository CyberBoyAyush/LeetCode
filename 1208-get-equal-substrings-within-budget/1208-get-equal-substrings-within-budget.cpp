// Sliding Window
// TC - O(n)
// SC - O(1)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(); // equals to t.length()

        int i = 0, j = 0;
        int currCost = 0;
        int maxLen = 0;

        while(j<n){
            //expansion
            currCost += abs(s[j] - t[j]);

            //shrinking
            while(currCost > maxCost){
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            maxLen = max(maxLen , j-i+1);
            j++;
        }
        return maxLen;
    }
};