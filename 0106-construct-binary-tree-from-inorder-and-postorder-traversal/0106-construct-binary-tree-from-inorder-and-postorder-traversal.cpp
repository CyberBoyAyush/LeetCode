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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int pStart,int pEnd){
        if(inStart>inEnd){
            return nullptr;
        }

        //create root
        TreeNode * root = new TreeNode(postorder[pEnd]);
        //finding root val in inorder
        int i = inStart;
        for(; i<=inEnd;i++){
            if(inorder[i] == root->val){
                break;
            }
        }

        // finding size of left and right part
        int leftsize = i-inStart;
        int rightsize = inEnd - i;

        //recursion call
        root->left = solve(inorder,postorder,inStart,i-1,pStart,pStart + leftsize-1);
        root->right = solve(inorder,postorder,i+1,inEnd,pEnd-rightsize,pEnd-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0;
        int inEnd = n-1;

        int pStart = 0;
        int pEnd = n-1;

        return solve(inorder,postorder,inStart,inEnd,pStart,pEnd);
    }
};