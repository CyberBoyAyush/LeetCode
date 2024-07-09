class Solution {
public:
// Iterative
    // TreeNode* BST(vector<int> &Tree, int start,int end){
    //     if(start>end){
    //         return nullptr;
    //     }
        
    //     // mid
    //     int mid = start + (end-start+1) / 2; // bcz we need ceil val
    //     TreeNode* root = new TreeNode(Tree[mid]);
    //     root->left = BST(Tree,start,mid-1);
    //     root->right = BST(Tree,mid+1,end);
        
    //     return root;
    // }
    // TreeNode* sortedListToBST(ListNode* head) {
    //     vector<int> Tree;
    //     //pushing ll data to arr
    //     while(head){
    //         Tree.push_back(head->val);
    //         head = head->next;
    //     }
        
    //     return BST(Tree,0,Tree.size()-1);
    // }

    // Recursive
    TreeNode* BST(ListNode* head, ListNode* tail){
        if(head==tail){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=tail && fast->next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }

        // node creation
        TreeNode* root = new TreeNode(slow->val);
        root->left = BST(head,slow);
        root->right = BST(slow->next,tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head){
        if(!head){
            return NULL;
        }
        return BST(head,NULL);
    }
};