class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // base case
        if(!head || !head->next){
            return head;
        }

        // recursive call
        ListNode* temp = insertGreatestCommonDivisors(head->next);

        // gcd node
        ListNode* gcdNode = new ListNode(__gcd(head->val,head->next->val));

        // now creating connections
        gcdNode->next = temp;
        head->next = gcdNode;

        return head;

    }
};