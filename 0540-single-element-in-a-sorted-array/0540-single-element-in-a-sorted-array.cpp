class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
	map <int,int> mpp;

	for(int i = 0; i<n;i++){
		mpp[nums[i]]++;
	}
    int el;
	for(auto it:mpp){
		if(it.second==1){
			el=it.first;
		}
	}
        return el;
    }
};