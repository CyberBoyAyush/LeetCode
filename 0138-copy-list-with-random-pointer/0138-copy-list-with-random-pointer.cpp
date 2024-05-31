/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // step1: creating new copy copy nodes and putting it in between nodes.
        Node* temp = head;
        while(temp!=nullptr){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next; // bcz next node is 2 steps away
        }

        // step2: placing random pointers
        temp = head;
        while(temp){
            Node* copyNode = temp->next;
            //checking if random exists
            if(temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;

            temp = temp->next->next;
        }

        // step3: connecting next pointers
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        temp = head;
        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next; // we are relinking the original LL
            res = res->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};