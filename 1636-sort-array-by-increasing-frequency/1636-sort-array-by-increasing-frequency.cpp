class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int &num : nums) {
            mp[num]++;
        }

        auto lambda = [&](int &num1, int &num2) {
            if(mp[num1] == mp[num2]) {
                return num1 > num2;
            }

            return mp[num1] < mp[num2];
        };

        sort(begin(nums), end(nums), lambda);

        return nums;
    }
};