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

// using morris traversal tc - O(n) sc - O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            // checking the left part
            if(!root->left){
                root = root->right;
            }
            
            else{
                //exists
                TreeNode* curr = root-> left;
                
                //traverse for linking
                while(curr->right){
                    curr = curr->right;
                }
                
                // changing the links
                curr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};