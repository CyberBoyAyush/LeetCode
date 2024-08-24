class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long>> t(n+1, vector<long>(2,0)); // even:0 , odd:1

        for(int i = 1 ; i<n+1 ; i++){
            //even
            t[i][0] = max(t[i-1][1] - nums[i-1] , t[i-1][0]);

            // odd
            t[i][1] = max(t[i-1][0] + nums[i-1] , t[i-1][1]);
        }

        return max(t[n][0], t[n][1]);
    }
};