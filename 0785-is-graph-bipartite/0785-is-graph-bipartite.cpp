class Solution {
public:
    // BFS -> Approach 1
// bool BFS(int node,vector<vector<int>>& adj,vector<int> &color){
//         queue<int> q;
//         q.push(node);
//         color[node] = 0; // initial colour as 0
        
//         while(!q.empty()){
//             int vertex = q.front();
//             q.pop();
            
//             for(int &v:adj[vertex]){
//                 // colour not assigned
//                 if(color[v]==-1){
//                     color[v] = (color[vertex] + 1) % 2;
//                     q.push(v);
//                 }
//                 // color assigned
//                 if(color[v]==color[vertex]){
//                     return 0;
//                 }
//             }
//         }
//         return 1;
//     }
//     bool isBipartite(vector<vector<int>>& adj) {
//         int V = adj.size();
//          vector<int> color(V,-1);
	    
// 	    for(int i = 0; i<V;i++){
//             if(color[i]==-1){
//                 if(!BFS(i,adj,color))    return 0;
//             }
// 	    }
// 	    return 1;
//     }

    // dfs ->  Approach 2
    bool BFS(int node , vector<vector<int>>& adj,vector<int> &color){
        // look for neighbours
        for(int &v:adj[node]){
            // color not assigned to neighbour : v
            if(color[v]==-1){
                // color assign karo
                color[v] = (color[node] + 1) % 2; // alternate color assign
                // recursive call
                if(!BFS(v,adj,color))
                    return 0;
            }
            
            // color is assigned
            else{
                if(color[v]==color[node]){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V,-1);
        
        // every node
        for(int i = 0; i<V; i++){
            if(color[i]==-1){
                color[i] = 0;
                if(!BFS(i,adj,color))   return 0;
            }
        }
        return 1;
    }
};