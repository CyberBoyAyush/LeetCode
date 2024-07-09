class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = NULL; // shows are current TreeNode we are on
        TreeNode* First = NULL, *Second = NULL; // our faulty nodes
        TreeNode* last = NULL, *present = NULL; // checking which is faulty TreeNode
        
        
        while(root){
            // Morris Traversal
            if(!root->left){
                last = present;
                present = root;
                
                //checking inconsistency
                if(last && last->val > present->val){
                    // found faulty nodes
                    // agar paheli baar h
                    if(!First)
                        First = last;
                    
                    Second = present;    
                }
                root = root->right;
            }
            else{
                // left exisits krta hai
                curr = root->left;
                
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                
                // Left side traverse nahi hui
                if(!curr->right){
                    curr->right = root;
                    root = root->left;
                }
                
                // left side traversed hai
                else{
                    curr->right = NULL;
                    last = present;
                    present = root;
                    
                    // checking inconsistency
                    if(last && last->val > present->val){
                    // found faulty nodes
                    // agar paheli baar h
                        if(!First)
                            First = last;
                    
                        Second = present;
                    }
                    root = root->right;
                }
            }
        }
        
        // swapping krdo
        int num = First->val;
        First->val = Second -> val;
        Second -> val = num;
    }
};