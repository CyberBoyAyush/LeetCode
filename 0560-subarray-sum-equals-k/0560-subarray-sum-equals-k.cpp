// Prefix sum (O(n))
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1; // edge case

        for(int i = 0; i<n; i++){
            sum+=nums[i]; // cummulative sum
            if(mpp.find(sum-k) != mpp.end()){
                res += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return res;
    }
};