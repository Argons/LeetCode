// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

class Solution {
public:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, 
                    int start, int end, int postStart, int postEnd) {
        if (start > end || postStart > postEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        // Record the index of root node in the inorder array.
        int inorderRootIdx;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == postorder[postEnd]) {
                inorderRootIdx = i;
                break;
            }
        }

        // Note that the range of postorder array of sub-trees 
        // should be adjusted by postStart - start.
        root->left  = build(inorder, postorder, start, inorderRootIdx-1, 
                            postStart, postStart-start+inorderRootIdx-1);
        root->right = build(inorder, postorder, inorderRootIdx+1, end, 
                            postStart-start+inorderRootIdx, postEnd-1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty())
            return NULL;
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
