class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //for storing the max number in the series of min number of elmeents in rows
        // for lucky number we need minimum in every row. SO for that minimums we will take the maximum out of it in count
        int rMinMax = INT_MIN;

        for(int row = 0; row<n; row++){
            int rMin = INT_MAX; // storing the minimum in row
            for(int col = 0;col<m;col++){
                rMin = min(rMin,matrix[row][col]);
            }
            // updating max out of that min
            rMinMax = max(rMinMax,rMin);
        }

        // now we need minimum of the maximum in col
        int cMaxMin = INT_MAX;

        for(int col = 0; col<m; col++){
            int cMax = INT_MIN; // storing the minimum in row
            for(int row = 0;row<n;row++){
                cMax = max(cMax,matrix[row][col]);
            }
            // updating min out of that max
            cMaxMin = min(cMaxMin,cMax);
        }

        // now we return the lucky num
        if(rMinMax == cMaxMin){
            return {rMinMax}; // or cMaxMin as both are same
        }

        return {};
    }
};