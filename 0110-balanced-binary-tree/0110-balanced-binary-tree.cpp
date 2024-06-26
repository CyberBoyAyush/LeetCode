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
    int height(TreeNode* root, bool& valid){
        if(root==nullptr){
            return 0; // heght of null node is 0
        }
        
        // for left side height
        int L = height(root->left,valid);
        
        // for right side height
        int R = height(root->right,valid);
        
        // checking balanced condition
        if(abs(L-R)>1){
            // means not balanced
            valid = 0;
        }
        
        return 1 + max(L,R);
    }
    bool isBalanced(TreeNode* root) {
        bool valid = 1; // considering our BT is balanced
        height(root,valid); // wee sending valid 
        return valid;
    }
};