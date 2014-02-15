// Given a binary tree, return the preorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

class Solution {
public:
    void preorder(TreeNode *root, vector<int> &num) {
        if (root == NULL)
            return;
        num.push_back(root->val);
        preorder(root->left, num);
        preorder(root->right, num);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};
