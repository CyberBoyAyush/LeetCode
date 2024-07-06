class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int target) {
        // Base Case
    if(!root){
        return NULL;
    }
    
    //left
    if(root->val > target){
        root->left = deleteNode(root->left,target);
        return root;
    }
    
    // right
    else if(root->val < target){
        root->right = deleteNode(root->right,target);
        return root;
    }
    
    else{
        // root->val == target
        // TreeNode we delete is leaf TreeNode
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        
        // TreeNode we delete has one child
        else if(!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        
        else if(!root->right){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // both child exists
        else{
            // find greater element from left or smaller from right we are finding greater from left
            TreeNode* child = root->left;
            TreeNode* parent = root;
            
            //right most 
            while(child->right){
                parent = child;
                child = child->right;
            }
            
            // case where root and parent is diff
            if(root!=parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            
            // other case
            else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
    }
};