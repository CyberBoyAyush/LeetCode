class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int,vector<int> , greater<int>> pq;

        // pushing first largest k el 
        for(int i = 0; i<k;i++){
            pq.push(nums[i]);
        }

        // do operations on rest of the arr
        for(int i = k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                //we got 1 larger el
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};