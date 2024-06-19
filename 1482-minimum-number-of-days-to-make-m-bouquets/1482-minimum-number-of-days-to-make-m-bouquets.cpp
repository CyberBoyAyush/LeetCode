class Solution {
public:
    int getNumOfB(vector<int>& bloomDay , int mid , int k){
        int cnt = 0;
        int noOfB = 0; // no of bouquets

        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                cnt = 0;
            }
            if(cnt==k){
                noOfB++;
                cnt = 0;
            }
        }
        return noOfB;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = *max_element(bloomDay.begin() , bloomDay.end() ); // maximum element present in the array bloom day
        int minDays = -1;
        while(start<=end){
            int mid = start + (end-start) / 2;
            if(getNumOfB(bloomDay,mid,k) >= m){
                minDays = mid; // mid hi hamara minDays hai
                end = mid - 1; // we will cheeck for any other minimum day possible
            }
            else{
                start = mid + 1;
            }
        }
        return minDays;
    }
};