class Solution{
  public:
    int numberOfSubarrays(vector<int> &nums,int k){
        // Prefix Sum using Map
        // TC - O(n)  SC - O(n)
        int n = nums.size();

        // map for keeping track
        unordered_map<int, int> mpp;

        int res = 0;
        int oddCnt = 0;
        mpp[0] = 1; // we have already seen oddCnt 0 in past

        for (int i = 0; i < n; i++) {
            oddCnt += (nums[i] % 2);

            if (mpp.find(oddCnt - k) != mpp.end()) {
                res += mpp[oddCnt - k];
            }

            mpp[oddCnt]++;
        }
        return res;
    }
};

// ************************************************************************************************************************************************

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Optimal - Using Sliding Window
        // TC - O(n) Sc- O(1)
        int n = nums.size();
        int oddCnt = 0; // counts the odd numbers in window
        int count = 0; // To count subarrays with exactly k odd numbers ending at the current j
        int result = 0; // result

        int i = 0, j = 0;

        while(j<n){
            if(nums[j] % 2 != 0){
                //means nums[j] off hai
                oddCnt ++;
                count = 0; //Reset the count whenever we encounter a new odd number
            }

            while(oddCnt == k){
                count++; // count the valid subarray ending at j

                // If the number at the left pointer i is odd, decrement oddCount
                if (nums[i] % 2 == 1) {
                    oddCnt--;
                }
                i++; // Move the left pointer to the right to shrink the window
            }

            result += count;
            j++;
        }
        return result;
    }
};
