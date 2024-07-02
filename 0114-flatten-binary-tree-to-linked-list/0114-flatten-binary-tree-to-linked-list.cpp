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