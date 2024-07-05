class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int target) {
        //base case
    if(!root){
        TreeNode* temp = new TreeNode(target);
        return temp;
    }

    //recursion
    if(target<root->val){
        root->left = insertIntoBST(root->left,target);
    }
    else if(target>root->val){
        root->right = insertIntoBST(root->right,target);
    }

    return root;
    }
};