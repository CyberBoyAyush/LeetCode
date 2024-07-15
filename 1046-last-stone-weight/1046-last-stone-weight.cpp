class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // maxheap

        for(auto it:stones) pq.push(it);

        int lastStoneWeight = 0;

        while(pq.size()>1){
            int bigStone = pq.top();
            pq.pop();
            int bigStone2 = pq.top();
            pq.pop();

            if(bigStone > bigStone2){
                int diff = bigStone - bigStone2;
                pq.push(diff);
            }
            else if(bigStone2>bigStone){
                int diff2 = bigStone2 - bigStone;
                pq.push(diff2);
            }
            else{
                pq.push(0);
            }
        }

        lastStoneWeight = pq.top();
        return lastStoneWeight;
    }
};