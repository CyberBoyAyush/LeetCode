class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;

        long long sum = 0;
        // pushing values in pq
        for(auto it:target){
            pq.push(it);
            sum+=it;
        } 
        long long element , remSum, maxElement;
        while(pq.top()!=1){
            maxElement = pq.top();
            pq.pop();
            remSum = sum - maxElement;
            // base codnition
            if(remSum <= 0 || remSum>=maxElement){
                return 0; // out of range
            }
            element = maxElement % remSum;
            if(element == 0){
                if(remSum!=1){
                    return 0;
                }
                else{
                    return  1;
                }
            }
            pq.push(element);
            sum = remSum+element;
        }
        return 1;
    }
};