/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       // Base cases
        if(p== nullptr && q == nullptr){
            // means they aree same
            return 1;
        }
        
        if((p && !q) || (!p && q)){
            // it means one exists and other one does not hence not same
            return 0;
        }
        
        if(p->val != q->val){
            // val does not means not same
            return 0;
        }
        
        // Now we will go left and right to check
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        // if both is true it will return true it means samee BT 
    }
};