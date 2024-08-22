class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0; // t-2
        int prev = nums[0];

        for(int i = 2; i<=n ; i++){
            int skip = prev;
            int steal = prev2 + nums[i-1];

            int curr = max(skip,steal);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};