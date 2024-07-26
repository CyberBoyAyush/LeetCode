class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // creating indegree and adj list
        unordered_map<int,vector<int>> adj;
        vector<int> inDeg(n,0);

        for(int i = 0 ; i<relations.size() ; i++){
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            adj[u].push_back(v);
            inDeg[v]++;
        }

        // kahn's algo topo sort
        queue<int> q;
        vector<int> maxTime(n,0);
        //pushing indegree 0 nodes in q
        for(int i = 0 ; i<n ; i++){
            if(!inDeg[i]){ 
                q.push(i);
            maxTime[i] = time[i]; 
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // neighbour traverse kro
            for(int & v : adj[node]){
                maxTime[v] = max(maxTime[v] , maxTime[node] + time[v]);
                inDeg[v]--;
                if(!inDeg[v]){
                    q.push(v);
                }
            }
        }
        return *max_element(maxTime.begin(),maxTime.end());
    }
};