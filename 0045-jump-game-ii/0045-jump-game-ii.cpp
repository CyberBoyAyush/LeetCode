class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r= 0;
        while(r < n-1){
            int farthestTravel = 0;
            for(int i = l ; i<=r ; i++){
                farthestTravel = max(farthestTravel,i + nums[i]);
            }
            l = r+1;
            r = farthestTravel;
            jumps = jumps+1;
        }
        return jumps;
    }
};