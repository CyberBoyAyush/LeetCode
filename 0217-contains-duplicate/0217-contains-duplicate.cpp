class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        for(auto x:mpp){
            if(x.second>1){
                return true;
            }
        }
        return false;
    }
};