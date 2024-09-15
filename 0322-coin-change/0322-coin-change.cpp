class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        
        // Initialization
        for(int target = 0 ; target<=amount; target++){
            if(target % coins[0] == 0){
                prev[target] = target / coins[0];
            }
            else{
                prev[target] = 1e9;
            }
        }

        // filling rest
        for(int idx = 1 ; idx<n ; idx++){
            for(int target = 0 ; target <= amount; target ++){
                int notTake = 0 + prev[target];
                int take = INT_MAX;
                if (coins[idx] <= target) {
                take = 1 + curr[target-coins[idx]];
                // we did not reduce 1 to idx as we have inifinite supply of coins
                }

                curr[target] = min(take,notTake);
            }
            prev = curr;
        }

        return (prev[amount] == 1e9) ? -1 : prev[amount];
    }
};