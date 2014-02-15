// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

class Solution {
public:
    void inorder(TreeNode *root, vector<int> &num) {
        if (root == NULL)
            return;
        inorder(root->left, num);
        num.push_back(root->val);
        inorder(root->right, num);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
