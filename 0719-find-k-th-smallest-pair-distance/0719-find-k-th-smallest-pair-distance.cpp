class Solution {
public:
    int slidingWindow(vector<int> &nums, int dist){
        int i = 0;
        int j = 1;

        int n = nums.size();
        int pairCount = 0;
        
        while(j < n){
            while(nums[j] - nums[i] > dist){
                i++;
            }
            pairCount += j-i;
            j++;
        }

        return pairCount;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        // sort the array
        sort(nums.begin(),nums.end());

        // Apply Binary Search to find distance 
        int l = 0;
        int h = nums[n-1] - nums[0]; // diff or highest and lowest

        int result = 0;

        while(l <= h){
            int mid = (l + h) / 2;

            int countPairs = slidingWindow(nums,mid);

            if(countPairs < k){
                l = mid +1;
            }
            else{
                result = mid;
                h = mid - 1; // go check smallest if there is any smaller than that
            }
        }

        return result;
    }
};