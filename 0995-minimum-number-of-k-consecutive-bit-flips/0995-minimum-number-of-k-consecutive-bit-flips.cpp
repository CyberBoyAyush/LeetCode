// Bruteforce TLE
// Tc - O(n*k) Sc- O(1)

// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int n = nums.size();
//         int flip = 0;
//         for(int i = 0; i<n; i++){
//             if(nums[i] == 0){
//                 if(i + k - 1 >= n){ // window nahi ban paa rhai last wali n cross krdiya
//                     return -1;
//                 }
//                 else{
//                     for(int j = i; j<= i+k-1; j++){
//                         nums[j] = !nums[j]; // 0 --> 1 and 1--> 0
//                     }
//                     flip++;
//                 }
//             }
//         }
//         return flip;
//     }
// };


// Optimal Solution - Using Queue
// Tc - O(n) Sc- O(n)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q; // queue for storing till which indeex it is reverses
        int flip = 0; // stores the count of flips

        for(int i = 0; i<n ;i++){
            // cheeck front of queue and remove it if exceeds
            if(!q.empty() && q.front() < i){
                q.pop();
            }

            // check flips 
            if( q.size() % 2 == nums[i] ){
                //edge case --> k window exceeds
                if(i + k -1 >= n){
                    return -1;
                }
                //push the index till when we are reversing
                q.push(i + k -1);
                flip++;
            }
        }
        return flip;
    }
};