// Given a binary tree, find the maximum path sum.
// The path may start and end at any node in the tree.

// For example:
// Given the below binary tree,
//    1
//   / \
//  2   3
// Return 6.

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int curSum;
        int maxSum = INT_MIN;
        maxPathSum(root, curSum, maxSum);
        return maxSum;
    }

    void maxPathSum(TreeNode *root, int &curSum, int &maxSum) {
        if (root == NULL)
            return;
        int lSum = 0, rSum = 0;
        maxPathSum(root->left, lSum, maxSum);
        maxPathSum(root->right, rSum, maxSum);

        // Compare following paths:
        //  left sub-tree path + root node;
        //  right sub-tree path + root node;
        //  left path + root node + right path.
        curSum = max(root->val, max(root->val + lSum, root->val + rSum));
        maxSum = max(maxSum, max(curSum, root->val + lSum + rSum));
    }
};
