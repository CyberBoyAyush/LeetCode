class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(auto it:gifts) pq.push(it);

        long long giftRemaining = 0;

        while(k--){
            int x = pq.top();
            
            pq.pop();

            pq.push(sqrt(x));
        }

        while(!pq.empty()){
            giftRemaining += pq.top();
            pq.pop();
        }
        return giftRemaining;
    }
};