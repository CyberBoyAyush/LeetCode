class Solution {
public:
    void floydd(int n, vector<vector<int>> &SPM){
        for(int via = 0; via < n ; via++){
            for(int i = 0 ; i< n ; i++){
                for(int j = 0 ; j<n ; j++){
                    SPM[i][j] = min(SPM[i][j] , SPM[via][j] + SPM[i][via]);
                }
            }
        }
    }

    int findResCity(int n,vector<vector<int>> &SPM, int distanceThreshold){
        int resultCity = -1;
        int leastCityReachCnt = INT_MAX;

        for(int i = 0; i<n ; i++){
            int countReach = 0;
            for(int j = 0; j<n ; j++){
                if(i != j && SPM[i][j] <= distanceThreshold){
                    countReach++;
                }
            }

            if(countReach <= leastCityReachCnt){
                leastCityReachCnt = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Using Dijkstra's Algorithm

        // This matrix store the Shortest path from each node to another node
        vector<vector<int>> SPM(n, vector<int>(n, 1e9 + 7));

        // filling initial matrix of self path
        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0; // dist from self to self will be 0
        }


        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        // calling floyd warshall algo for every city
        floydd(n,SPM);

        // we find the city by iterating over SPM
        return findResCity(n, SPM, distanceThreshold);

    }
};