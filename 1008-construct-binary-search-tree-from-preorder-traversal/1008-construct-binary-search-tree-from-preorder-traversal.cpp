class Solution {
public:
    TreeNode* BST(vector<int> &preorder,int &idx,int low ,int high){
        if(idx == preorder.size() || preorder[idx]<low || preorder[idx]>high){
            return NULL;
        }

        // node creation
        TreeNode * root = new TreeNode(preorder[idx++]);
        root->left = BST(preorder,idx,low,root->val);
        root->right = BST(preorder,idx,root->val,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return BST(preorder,idx,INT_MIN,INT_MAX);
    }
};