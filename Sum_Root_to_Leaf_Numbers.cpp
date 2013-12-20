// Given a binary tree containing digits from 0-9 only, 
// each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.

// For example,
//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = 12 + 13 = 25.

class Solution {
public:
    int getSum(TreeNode *root, int value)
    {
        if (root == NULL)   
            return 0;
        value = value * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            return value;
        return getSum(root->left, value) + getSum(root->right, value);
    }
    int sumNumbers(TreeNode *root) {
        return getSum(root, 0);
    }
};
