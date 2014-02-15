// Given an array where elements are sorted in ascending order, 
// convert it to a height balanced BST.

class Solution {
public:
    TreeNode *buildTree(vector<int> &num, int start, int end) {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        if (start == end)
            return root;
        root->left  = buildTree(num, start, mid-1);
        root->right = buildTree(num, mid+1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildTree(num, 0, num.size()-1);
    }
};
