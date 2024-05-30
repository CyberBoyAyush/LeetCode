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

    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp){
            if(cnt==k) break;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k==0){
            return head;
        }

        // finding length of LL & tail
        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        if(k%len == 0 ) return head;
        k = k%len; // for lerger values of k

        tail->next = head;
        ListNode* nthNode = findNthNode(head, len - k);
        head = nthNode -> next;
        nthNode->next = NULL;
        return head;

    }
};