class KthLargest {
public:
// Min heap
    priority_queue<int , vector<int> , greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;

        for(auto &num : nums){
            pq.push(num);

            if(pq.size() > K){
                pq.pop();
            }
        }

        
    }
    
    int add(int val) {
        // for add
        pq.push(val);

        if(pq.size() > K){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */