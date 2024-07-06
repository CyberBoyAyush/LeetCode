class Solution {
public:
    bool isBST(TreeNode* root,long long min,long long max){
        if(!root){
            return true;
        }

        if(root->val > min && root->val < max){
            bool left = isBST(root->left,min,root->val);
            bool right = isBST(root->right,root->val,max);
            return left && right;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};