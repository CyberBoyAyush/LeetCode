class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // we take prefix sum row wise
        for(int row = 0; row<rows ; row++){
            for(int col = 1 ; col<cols; col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }

        // Now we find no of submatrix with sum k (Leeetcode - 560) in downwards dirn (cols)
        int result = 0;
        for(int startcol = 0; startcol<cols; startcol++){
            for(int j = startcol ; j<cols; j++){
                // niche move kr rahe hai hum
                unordered_map<int,int> mpp;
                mpp[0] = 1; // EDGE CASE

                int curSum = 0;
                for(int row = 0 ; row<rows ; row++){
                    curSum += matrix[row][j] - (startcol > 0 ? matrix[row][startcol-1] : 0);
                    // bcz row me pichli row ka sum hai (hum prefix usm me khel rhe hai dosto)

                    if(mpp.find(curSum - target) != mpp.end()){
                        result += mpp[curSum - target];
                    }
                    mpp[curSum]++;
                }
            }
        }
        return result;
    }
};