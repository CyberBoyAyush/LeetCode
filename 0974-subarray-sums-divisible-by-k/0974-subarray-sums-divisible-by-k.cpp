class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        
        int n = nums.size();

        int sum = 0;

        int res = 0;

        mpp[0] = 1; //edge case handling for 0 rem

        for(int i = 0; i<n;i++){
            sum += nums[i];

            int rem = sum%k;

            if(rem<0){
                rem += k; // negative remainder handling for map
            }

            if(mpp.find(rem) != mpp.end()){
                res += mpp[rem];
            }

            mpp[rem]++;
        }
        return res;
    }
};