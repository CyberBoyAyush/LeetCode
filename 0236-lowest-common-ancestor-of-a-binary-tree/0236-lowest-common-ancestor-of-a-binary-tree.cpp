class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }

        if(root == p || root == q){
            return root;
        }

        // use recursion to find left and right side
        TreeNode* leftN = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN = lowestCommonAncestor(root->right,p,q);

        // leftN mila but rightN nhi
        if(leftN == nullptr){
            return rightN;
        }

        if(rightN == nullptr){
            return leftN;
        }

        return root;
    }
};