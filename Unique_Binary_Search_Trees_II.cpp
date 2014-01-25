// Given n, generate all structurally unique BST's that store values 1...n.
//
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        // If the range is invalid, then return an empty tree
        if (start > end) 
            return vector<TreeNode *>(1);

        vector<TreeNode *> result;
        for (int i = start; i <= end; ++i) {
            // Generate all possible left subtrees (including the empty subtree)
            vector<TreeNode *> leftSubtrees = generateTrees(start, i-1);

            // Generate all possible right subtrees (including the empty subtree)
            vector<TreeNode *> rightSubtrees = generateTrees(i+1, end);

            // For each left subtree and each right subtree, create a root node
            // with value i and then link the two subtrees to the root
            for (int j = 0; j < leftSubtrees.size(); ++j) {
                for (int k = 0; k < rightSubtrees.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
