/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Bruteforce
//         if(head->next == nullptr){
//             return nullptr;
//         }
//         ListNode* temp = head;
//         int n = 0;
//         while(temp){
//             n++;
//             temp = temp->next;
//         }

//         int res = n/2;
//         temp = head;
//         while(temp){
//             res--;
//             if(res==0){
//                 ListNode* middle = temp->next;
//                 temp->next = temp->next->next;
//                 delete middle;
//                 break;
//             }
//             temp = temp->next;
//         }
//         return head;
        
        // Optimal
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next; // skipping one iteration of slow by moving fast
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;
        return head;
        
    }
};