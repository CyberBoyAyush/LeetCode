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

    // Parent function for checking the parent
    bool parents(TreeNode* root,int a , int b){
        if(!root){
            return 0; // root does not exists
        }

        if(root->left && root->right){
            // we will check for values a and b in it
            if(root->left->val == a && root->right->val == b){
                return 1;
            }
            //alternate case can be possible
            if(root->left->val == b && root->right->val == a){
                return 1;
            }
        }

        // we use recursion to check in left and right
        return parents(root->left,a,b) || parents(root->right,a,b); // if any side its true it is true
    }
    bool isCousins(TreeNode* root, int a, int b) {
        // we use queue for traversal
        queue<TreeNode*> q;
        q.push(root);

        //levels for checking
        int l1 = -1, l2 = -1;

        //for current level
        int currLevel = 0;

        while(!q.empty()){
            // for level checking and upgradatation
            int n = q.size();
            while(n--){ // n jabtak 0 nhi ho jata
                TreeNode* temp = q.front();
                q.pop();
                if(temp->val == a){
                    l1 = currLevel;
                }
                if(temp->val == b){
                    l2 = currLevel;
                }

                // putting their childerens in it
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            currLevel ++; // level badh gaya

            // checking levels of our a and b
            if(l1!=l2){
                //level same nhi h
                return 0; // false return kardo
            }

            // we have found the levels same
            if(l1!=-1){
                break;
            }
        }

        return !parents(root,a,b); // 0 hai toh 1 , 1 hai to 0

    }
};