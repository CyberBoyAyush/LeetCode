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
        // Burn func for timer and recursion
    int Burn(TreeNode* root,int &timer, int start){
        // base case root does not exists
        if(!root){
            return 0;
        }
        
        //Node Exists
        
        // condition 1 : it is a start node( we return burn time)
        if(root->val == start){
            return -1;
        }
        
        // condition 2 : normal node
        int left = Burn(root->left,timer,start);
        int right = Burn(root->right,timer,start);
        
        // now checking for burn condition and timer update
        // we get burn from left side
        if(left<0){
            timer = max(timer, abs(left) + right);
            return left-1;
        }
        // we get burn from right side
        if(right<0){
            timer = max(timer, abs(right) + left);
            return right-1;
        }
        
        // if no burn then return height
        return 1 + max(left,right);
        
    }
    
    // function for finding the loaction of start node
    void findBurnNode(TreeNode* root,int start,TreeNode* &BurnNode){
        if(!root){
            return;
        }
        
        if(root->val == start){
            BurnNode = root;
            return;
        }
        
        findBurnNode(root->left,start,BurnNode);
        findBurnNode(root->right,start,BurnNode);
        
        
    }
    
    // func for finding the height below the start node
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        
        return 1 + max(height(root->left) , height(root->right));
    }
    int amountOfTime(TreeNode* root, int start)
    {
        // timer for the calculation of time
        int timer = 0;
        
        // recursive function that find the timer
        Burn(root,timer,start);
        
        // now for the tree below start node
        
        // first finding the start node
        TreeNode* BurnNode = NULL;
        findBurnNode(root,start,BurnNode);
        
        //Now finding the height below it for calculation
        int h = height(BurnNode) - 1;
        
        // final answer
        return max(timer,h);
    }
};