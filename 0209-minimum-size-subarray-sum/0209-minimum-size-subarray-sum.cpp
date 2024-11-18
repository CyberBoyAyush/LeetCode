class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int len = INT_MAX;  // as we need minimum

        int sum = 0;

        int i = 0;
        int j = 0;

        while(j<n){
            sum += nums[j];

            while(sum >= target){
                len = min(len , j - i + 1);
                sum -= nums[i]; // shirnk the window for better ans
                i++;
            }
            j++;
        }

        return len == INT_MAX ? 0 : len;
    }
};