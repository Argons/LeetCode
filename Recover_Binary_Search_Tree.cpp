// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. 
// Could you devise a constant space solution?

class Solution {
public:
    void inorder(TreeNode *root, vector<TreeNode*> &BST, vector<int> &array) {
        if (root == NULL)
            return;
        inorder(root->left, BST, array);
        BST.push_back(root);
        array.push_back(root->val);
        inorder(root->right, BST, array);
    }

    // O(N) time complexity, O(N) space complexity
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> BST;
        vector<int> array;

        // inorder traversal of BST is a sorted array.
        inorder(root, BST, array);
        int i;
        for (i = 0; i < array.size()-1; i++) {
            if (array[i] > array[i+1])
                break;
        }
        for (int j = array.size()-1; j > i; j--) {
            if (array[j] < array[j-1]) {
                swap(BST[i]->val, BST[j]->val);
                return;
            }
        }
    }
};
