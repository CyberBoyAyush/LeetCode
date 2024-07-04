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
    int maxSum;

    // solve func for recursion
    int Solve(TreeNode* root){
        //base case
        if(!root){
            return 0;
        }

        int l = Solve(root->left);
        int r = Solve(root->right);

        //3 case conditions
        // only root is good sum
        int rootGood = root->val;

        // any one from left or right and root is good
        int oneGood = max(l,r) + root->val;

        // complete path with l , r and root is good
        int fullGood = l + r + root->val;

        //upfating maxSUm
        maxSum = max({maxSum,rootGood,oneGood,fullGood});

        //return
        return max(oneGood,rootGood);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        Solve(root);

        return maxSum;
    }
};