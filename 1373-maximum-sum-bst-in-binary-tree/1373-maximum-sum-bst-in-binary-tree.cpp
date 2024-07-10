class Solution {
public:
    class Box {
    public:
        bool BST;
        int sum;
        int min, max;

        // constructor
        Box() {
            BST = 1;
            sum = 0;
            min = INT_MAX;
            max = INT_MIN;
        }
    };

    // find func
    Box* find(TreeNode* root, int& totalSum) {
        // root does not exists
        if (!root) {
            return new Box();
        }

        // root exists
        Box* lefthead = find(root->left, totalSum);
        Box* righthead = find(root->right, totalSum);

        // BST hai valid
        if (lefthead->BST && righthead->BST && lefthead->max < root->val &&
            righthead->min > root->val) {
            Box* head = new Box();
            head->sum += lefthead->sum + righthead->sum + root->val;

            head->min = min(root->val, lefthead->min);

            head->max = max(root->val, righthead->max);

            totalSum = max(totalSum, head->sum);

            return head;
        }
        // bst not valid
        else {
            lefthead->BST = 0;
            return lefthead;
        }
    }
    int maxSumBST(TreeNode* root) {
        int totalSum = 0;
        find(root,totalSum);
        return totalSum;
    }
};