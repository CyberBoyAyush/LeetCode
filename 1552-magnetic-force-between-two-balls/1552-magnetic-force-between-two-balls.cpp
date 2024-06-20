class Solution {
public:
    bool isPossible(vector<int>& position , int mid , int m){
        int prev = position[0]; // first ball will be on pos 0
        int ballCnt = 1;
        for(int i = 0;i<position.size();i++){
            int curr = position[i];
            if(curr - prev >= mid){
                prev = curr;
                ballCnt++;
            }
        }
        return ballCnt >= m; // true if ballCnt is equal to m else false
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position),end(position));
        int s = 1;
        int e = position[n-1] - position[0]; // bcz arr is sorted
        int result;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(position,mid,m)){
                result = mid;
                s = mid + 1; // minimum magnetic force between any two balls is maximum.
            }
            else{
                e = mid -1;
            }
        }
        return result;
    }
};