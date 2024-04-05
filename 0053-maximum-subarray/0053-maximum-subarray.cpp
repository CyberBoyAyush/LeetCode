class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        long long maxi = LONG_MIN;
        for(int i = 0; i<n; i++){
        sum += arr[i];
        maxi = max(maxi,sum);
        if(sum<0){
            sum = 0;
        }
        }
            return maxi; 
        }
};