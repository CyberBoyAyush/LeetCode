// Using sliding window as minutes window is fix and we have to use consecutive elements
// TC - O(n)
// SC - O(1)

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currUnsat = 0;

        // we will first check current unsatifieed for 1st window
        for(int i = 0; i<minutes; i++){
            currUnsat += customers[i] * grumpy[i]; // smart way fo writing if grumpy[i] == 0
        }

        //calculation for further window
        int maxUnsat = currUnsat; // for now
        // variable for sliding window
        int i = 0;
        int j = minutes;
        while(j<n){
            // for every j increase
            currUnsat += customers[j] * grumpy[j];

            // for every i increase
            currUnsat -= customers[i] * grumpy[i];

            //updating maxUnsat
            maxUnsat = max(currUnsat , maxUnsat);

            i++;
            j++;
        }

        // calculating total satisfied customers
        int totalSat = maxUnsat; // we will use secret power in this window for minutes consecutive minutes
        for(int i = 0; i<n; i++){
            if(grumpy[i] == 0)
                totalSat += customers[i];
        }
        return totalSat;
    }
};