// Iterative Way

// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode* p1 = head->next;
//         ListNode* p2 = p1;

//         while(p2 != nullptr){
//             int sum = 0;
//             while(p2!=nullptr && p2->val != 0){
//                 sum += p2->val;
//                 p2 = p2->next;
//             }

//             p1->val = sum;
//             p2 = p2->next;
//             p1->next = p2;
//             p1 = p1->next;
//         }

//         return head->next;
//     }
// };


// Recursive Way
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        if(head==nullptr){
            return head;
        }

        ListNode* temp = head;

        int sum = 0;
        while(temp != nullptr && temp->val !=0){
            sum += temp->val;
            temp = temp->next;
        }

        head->val = sum;
        head->next = mergeNodes(temp);
        return head;
    }
};