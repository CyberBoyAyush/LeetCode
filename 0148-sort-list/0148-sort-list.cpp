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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2LL(ListNode* list1, ListNode* list2){
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;

        return dNode->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        // base case
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        // to make it two different ll
        middle->next = nullptr;

        //recursive call
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge2LL(leftHead,rightHead);
    }
};