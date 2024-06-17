class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;
        for(int i = 0; i<=n-m-1; i++){
            int k = 0;
            while(k<m){
                if(pattern[k]==1 && nums[i + k + 1] > nums[i + k]){
                    k++;
                }
                else if(pattern[k] == 0 && nums[i + k + 1] == nums[i + k]){
                    k++;
                }
                else if(pattern[k] == -1 && nums[i + k + 1] < nums[i + k]){
                    k++;
                }
                else{
                    break;
                }
            }
            if(k==m){// k out of bound hua matlab string follows rule
                count++;
            }
        }
        return count;
    }
};