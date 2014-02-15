// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).

// For example, this binary tree is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3

class Solution {
public:
    bool compare(TreeNode *sub1, TreeNode *sub2) {
        if (sub1 == NULL && sub2 == NULL)
            return true;
        if (sub1 == NULL || sub2 == NULL)
            return false;
        if (sub1->val != sub2->val)
            return false;
        return compare(sub1->left, sub2->right) &&
               compare(sub1->right, sub2->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }
};
