// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<pair<int,ListNode*> ,
//         vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;
//         for(int i = 0 ;i<lists.size();i++){
//             if(lists[i]){
//                 pq.push({lists[i]->val , lists[i]});
//                 }
//         }

//         ListNode* dNode = new ListNode(-1);
//         ListNode* temp = dNode;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             if(it.second->next){
//                 pq.push({it.second->next->val,it.second->next});
//             }
//             temp->next = it.second;
//             temp = temp->next;
//         }

//         return dNode->next;

//     }
// };

class Solution {
public:
    // custom comapre func
    class Compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; // heap ke case me ulta hota h -> minheap
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         // create a min heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq; // custom sort min heap
        
        for(auto node : lists){
            if(node) {
                pq.push(node);
            }
        }
        
        // creating some pointer nodes
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode; // traverse in LL and points to tail
        
        ListNode* temp; // we push values from min heap in it
        
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next!=nullptr)  pq.push(temp->next);
        }
        return dummyNode->next;
    }
};