class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Three Pointers Approach
        // int pickP = 0, pickM = 0, pickG = 0;
        // int travelP = 0, travelM = 0, travelG = 0;
        // int lastP = 0, lastG = 0, lastM = 0;

        // // calculate pick time
        // for(int i = 0; i<garbage.size();i++){
        //     string curr = garbage[i];
        //     for(int j = 0; j<curr.size();j++){
        //         char ch = curr[j];
        //         if(ch=='P'){
        //             pickP++;
        //             lastP = i;
        //         }
        //         else if(ch=='G'){
        //             pickG++;
        //             lastG = i;
        //         }
        //         else{
        //             pickM++;
        //             lastM = i;
        //         }
        //     }
        // }
        // // calculate travel time
        // for(int i = 0 ;i<lastP;i++){
        //     travelP += travel[i];
        // }
        // for(int i = 0; i<lastG;i++){
        //     travelG += travel[i];
        // }
        // for(int i = 0 ;i<lastM;i++){
        //     travelM += travel[i];
        // }

        // int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        // return ans;

        // Prefix Sum Appraoch
        int time = 0;

        int n = garbage.size();

        int M_idx = 0;
        int G_idx = 0;
        int P_idx = 0;

        for(int i =0; i<n;i++){
            for(int j=0; j<garbage[i].length();j++){
                if(garbage[i][j]=='M'){
                    M_idx = i;
                }
                else if(garbage[i][j]=='G'){
                    G_idx = i;
                }
                else{
                    P_idx = i;
                }
                time++;
            }
        }

        //prefix sum
        for(int i = 1 ;i<travel.size();i++){
            travel[i] = travel[i] + travel[i-1];
        }

        time += M_idx > 0 ? travel[M_idx - 1] :0;
        time += G_idx > 0 ? travel[G_idx - 1] :0;
        time += P_idx > 0 ? travel[P_idx - 1] :0;

        return time;
    }
};