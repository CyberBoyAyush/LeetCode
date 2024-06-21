// Sliding Window Two Pointer
// TC - O(n)
// Sc - O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){ // edge case
            return 0;
        }
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int prod = 1;

        while(j<n){
            // Expansion 
            prod *= nums[j];

            //shrinking
            while(prod>=k){ // prod>=k because we need prod<k strticly
                prod /= nums[i];
                i++;
            }

            cnt += (j-i)+1; // no of possible subarrrays till j
            j++;
        }
        return cnt;
    }
};