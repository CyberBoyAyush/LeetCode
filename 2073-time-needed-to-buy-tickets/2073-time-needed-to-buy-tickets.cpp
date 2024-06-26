class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // BruteForce [O(n*m)]
        queue<int> q;
        int n = tickets.size();
        // push all index in queue
        for(int i = 0; i<n; i++){
            q.push(i);
        }
        // set time = 0
        int time = 0;
        // now do operation for ticket and time
        while(tickets[k]!=0){
            tickets[q.front()]--;
            time++;
            if(tickets[q.front()]){ // agar q.front 0 nahi hai toh
                q.push(q.front());
                q.pop();
            }
            else{
                q.pop();
            }    
        }
        return time;
        
        // Optimal [0(n)]
        int time = 0;
        int n = tickets.size();
        for(int i = 0; i<n ;i++){
            if(i<=k){
                time += min(tickets[i],tickets[k]);
            }
            else{
                time += min(tickets[k]-1 , tickets[i]);
            }
        }
        return time;
    }
};
