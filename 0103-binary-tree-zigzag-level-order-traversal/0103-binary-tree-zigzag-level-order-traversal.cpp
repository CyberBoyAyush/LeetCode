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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {}; // Handle the case where the tree is empty

        // In this ques we are going to use two stacks one for r-->l and another for l-->r
        stack<TreeNode*> s1; // r-->l
        stack<TreeNode*> s2; // l-->r
        s1.push(root); // pushing root to s1
        vector<int> levels; // store different levels
        vector<vector<int>> ans; // final answers

        while(!s1.empty() || !s2.empty()){
            // Going R to L
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode* temp = s1.top();
                    s1.pop();
                    // pushing the val in level
                    levels.push_back(temp->val);


                    //R to L
                    if(temp->left)
                        s2.push(temp->left);
                    if(temp->right)
                        s2.push(temp->right);
                }
            }
            else if(!s2.empty()){
                while(!s2.empty()){
                    TreeNode* temp = s2.top();
                    s2.pop();
                    levels.push_back(temp->val);
                    //L to R
                    if(temp->right)
                        s1.push(temp->right);
                    if(temp->left)
                        s1.push(temp->left);
                }
            }
            ans.push_back(levels);
            levels.erase(levels.begin(),levels.end()); // we have to erase it for future use
        }
        return ans;
    }
};