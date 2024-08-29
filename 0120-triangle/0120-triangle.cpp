class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> front(n);

        for(int j = 0; j<n ; j++){
            front[j] = a[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            vector<int> curr(n);
            for(int j = i ; j>= 0; j--){
                int down = a[i][j] + front[j];
                int diagnol = a[i][j] + front[j+1];

                curr[j] = min(down,diagnol);
            }
            front = curr;
        }

        return front[0];
    }
};