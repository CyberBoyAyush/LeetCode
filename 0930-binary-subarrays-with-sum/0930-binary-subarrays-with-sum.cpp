// Approach 1 : Preefix using using map

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         unordered_map<int,int> mpp;
//         mpp[0] = 1;
//         int currSum = 0;
//         int res = 0;
//         for (int i = 0; i<n ;i++){
//             currSum += nums[i];

//             if(mpp.find(currSum - goal) != mpp.end()){
//                 res += mpp[currSum - goal];
//             }

//             mpp[currSum]++;

//         }
//         return res;
//     }
// };


// Optimal Code - Sliding Window
// Tc - O(n) Sc - O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int res = 0;
        int cntZeros = 0;
        int window_sum = 0;

        int i = 0, j = 0;

        while(j<n){
            window_sum += nums[j];

            while( i < j && (nums[i] == 0 || window_sum > goal)){
                if(nums[i] == 0){ 
                   cntZeros++; 
                }
                else{
                    cntZeros = 0;
                }

                window_sum -= nums[i];
                i++;
            }

            if(window_sum == goal){
                res += 1 + cntZeros;
            }

            j++;
        }
        return res;
    }
};