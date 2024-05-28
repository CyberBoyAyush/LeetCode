/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Map Approach
        // unordered_map<ListNode*,bool> mpp;
        // ListNode* temp = head;
        // while(temp){
        //     if(mpp[temp]) return true;
        //     mpp[temp] = true;
        //     temp = temp->next;
        // }
        // return false;

        // Tortoise And Hare (2 Pointers);
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(slow==fast) return true; // loop exists

        }
        return false;
    }
};