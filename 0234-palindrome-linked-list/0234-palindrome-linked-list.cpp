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
    ListNode* reverseList(ListNode* head) {
        // Iterative
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        /* // Brute Approach More Sapce
        stack<int> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            if(temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
        */

        // Optimal
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second){
            if(first->val != second->val){
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseList(newHead);
        return true;


    }
};