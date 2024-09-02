class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t[71][71];
        memset(t, -1, sizeof(t));  // Initialize the array with -1
        // t[c1][c2] = max cherries collected till row, c1 by rob 1 + row, c2 by rob 2

        t[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1]; // taking care of edge case here if both are standing in same col rob1 and rob 2

        for(int row = 1 ; row < m ; row++){
            int temp[71][71];
            memset(temp, -1, sizeof(temp));
            for(int c1 = 0; c1 <= min(n-1,row); c1++){
                for(int c2 = max(0,n - row - 1); c2 < n ; c2 ++){
                    // now taking in mind of all 9 possibilites
                    int prevRowMax = 0;
                    for(int prevCol1 = max(0, c1-1); prevCol1 <= min(n-1, c1 + 1); prevCol1++){
                        for(int prevCol2 = max(0,c2-1) ; prevCol2 <= min(n-1, c2 + 1); prevCol2++){
                            prevRowMax = max(prevRowMax, t[prevCol1][prevCol2]);
                        }
                    }

                    // filling ans
                    if(c1 == c2){
                        // same col
                        temp[c1][c2] = prevRowMax + grid[row][c1];
                    }
                    else{
                        temp[c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                }
            }

            for(int i = 0 ; i< n ;i++){
                for(int j = 0 ; j< n ; j++){
                    t[i][j] = temp[i][j];
                }
            }
        }

        int res = 0;
        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ; j< n ; j++){
                res = max(res, t[i][j]);
            }
        }
        return res;
    }
};