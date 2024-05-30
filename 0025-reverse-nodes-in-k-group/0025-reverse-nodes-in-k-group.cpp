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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base Case
        if (head == nullptr) {
            return nullptr;
        }

        // step 1: Check if there are at least k nodes to reverse
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        // If there are fewer than k nodes left, return head without reversing
        if (count < k) {
            return head;
        }

        // Step 2 : reverse k nodes
        ListNode* prev = nullptr;
        temp = head;
        ListNode* next = nullptr;
        count = 0;
        while (temp != nullptr && count < k) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        // recursive call;
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // return
        return prev;
    }
};