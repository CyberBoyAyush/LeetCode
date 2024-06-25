/**
 * Definition for a binary tree TreeNode.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
      queue<TreeNode*> q; // for tracking
      q.push(root);
      vector<vector<int>> ans; // for ans storing
      if (root == nullptr) {
            return ans; // Return an empty vector if the tree is empty
        }
      while(!q.empty()){
          int s = q.size();
          vector<int>v;
          for(int i = 0; i<s;i++){
            TreeNode* temp = q.front();// for keping track of nodes
            q.pop();
            v.push_back(temp->val);
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
            
          }
          ans.push_back(v);
      }
      return ans;
    }
};