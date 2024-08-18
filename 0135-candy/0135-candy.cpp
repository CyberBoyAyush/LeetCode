class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candy = n; // intial everyone has 1 candy

        int i = 1; // we are starting from 1

        while(i<n){
            // both ratings are same
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // increasing slope -> Peak
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak; // adding peak value in candy
                i++;

                // check for i == n
                if(i == n){
                    return candy;
                }
            }

            // decreasing slope -> dip
            int dip = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
                
            }
            // subtracting extra dip added in it
            candy -= min(peak,dip);
        }
        return candy;
    }
};