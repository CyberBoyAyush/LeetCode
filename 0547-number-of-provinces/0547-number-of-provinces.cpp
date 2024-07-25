class Solution {
public:
    int n; // stores the size
    void dfs(int node,unordered_map<int,vector<int>> &adj,vector<bool>& vis){
        vis[node] = 1;

        // traversal
        for(int &v : adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int cnt = 0; // stores the cnt
        // make adj list from matrix
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,0);

        // dfs call
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};