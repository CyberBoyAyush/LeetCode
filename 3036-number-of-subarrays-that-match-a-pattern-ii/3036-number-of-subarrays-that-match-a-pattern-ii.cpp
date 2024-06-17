class Solution {
public:
    void countLPS(vector<int>& pattern , vector<int>& LPS){
        int M = pattern.size();
        LPS[0] = 0;
        int len = 0;
        int i = 1;
        while(i<M){
            if(pattern[i] == pattern[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = nums.size();
        int M = pattern.size();
        vector<int> nums2;
        for(int i = 0; i<N-1;i++){
            if(nums[i]<nums[i+1]){
                nums2.push_back(1);
            }
            else if(nums[i]==nums[i+1]){
                nums2.push_back(0);
            }
            else{
                nums2.push_back(-1);
            }
        }

        vector<int> LPS(M,0);
        countLPS(pattern,LPS);

        int i = 0;
        int j = 0;
        int count = 0;
        while(i<nums2.size()){
            if(pattern[j]==nums2[i]){
                i++;
                j++;
            }
            if(j==M){
                count++;
                j = LPS[j-1];
            }
            else if(i< nums2.size() && pattern[j] != nums2[i]){
                if(j!=0){
                    j = LPS[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};