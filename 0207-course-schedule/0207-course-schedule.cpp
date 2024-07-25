class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int N = numCourses;
       int P =  prerequisites.size();

       vector<int> inDeg(N,0);
	    vector<int> adj[N];
	    
	    for(int i = 0 ;i<P; i++){
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	        inDeg[prerequisites[i][0]]++;
	    }
	    
	    // apply Kahn's Algo
	    
	    queue<int> q;
	    int cnt = 0;
	    
	    // pushing all indegree 0 el in queue
	    for(int i = 0 ; i<N; i++){
	        if(!inDeg[i])
	            q.push(i);
	    }
	    
	    // traversal
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        
	        // traversing th eneighbours
	        for(auto &v:adj[node]){
	            inDeg[v]--;
	            if(!inDeg[v]){
	                q.push(v);
	            }
	        }
	    }
	    
        return cnt == N;
    }
};