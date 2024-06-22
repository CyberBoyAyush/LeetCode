// Bruteforce ---> TLE
// TC - O(n*k)
// SC - O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans; // storing our answer

        for(int i = 0 ; i<= n-k; i++){
            int maxi = INT_MIN;
            for(int j = i; j<i+k; j++){
                maxi = max(maxi, nums[j]);
            }
            //pushing it in ans
            ans.push_back(maxi);
        }
        return ans;
    }
};


// Optimal Code Using Deque
// TC - O(n)
// SC - O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // deque for operations
        deque<int> d;
        // vector ans for answer
        vector<int> ans;

        // we will traverse first for k-1 elements
        for(int i = 0 ; i<k-1 ; i++){
            // jab tak next wala val bada hai purane walee ko deque se hatate rho
            while(!d.empty() && nums[i] > nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i); // otherwise push back krdo
        }

        // ab hum main calcuation krengee in our array for final answers
        for(int i = k-1; i<n; i++){
            // remove smaller elmenmts from back
            while(!d.empty() && nums[i] > nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i); // otherwise push back krdo

            // agar front window se bahar nikal gaya (window badh gayi)
            if(d.front() <= i-k){
                d.pop_front();
            }

            //ans calculate krlo
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};
