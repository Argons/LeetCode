// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

class Solution {
public:
    void postorder(TreeNode *root, vector<int> &num) {
        if (root == NULL)
            return;
        postorder(root->left, num);
        postorder(root->right, num);
        num.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
