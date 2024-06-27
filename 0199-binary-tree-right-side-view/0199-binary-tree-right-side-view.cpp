/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void RView(TreeNode * root,int level,vector<int>&ans){
        if(root == nullptr){
            return;
        }
        
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        
        //we r first then L
        RView(root->right,level+1,ans);
        RView(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
       int level = 0;
       RView(root,level,ans);
       return ans;
    }
};