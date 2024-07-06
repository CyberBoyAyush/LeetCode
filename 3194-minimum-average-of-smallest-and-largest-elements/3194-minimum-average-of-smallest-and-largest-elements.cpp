class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        double mini = (nums[left] + nums[right]) / 2.0;
        while(left<=right){
            int minel = nums[left];
            int maxel = nums[right];
            double avg = (minel + maxel) / 2.0;
            mini = min(mini, avg);
            left++;
            right--;
        }
        return mini;
    }
};