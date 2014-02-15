// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path 
// from the root node down to the farthest leaf node.

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int depthLeft  = 1 + maxDepth(root->left);
        int depthRight = 1 + maxDepth(root->right);
        return max(depthLeft, depthRight);
    }
};
