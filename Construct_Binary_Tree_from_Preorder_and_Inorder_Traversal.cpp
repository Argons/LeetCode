// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

class Solution {
public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, 
                    int start, int end, int inStart, int inEnd) {
        if (start > end || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[start]);

        int inRootIdx;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == preorder[start]) {
                inRootIdx = i;
                break;
            }
        }

        root->left  = build(preorder, inorder, start+1, start-inStart+inRootIdx,
                            inStart, inRootIdx-1);
        root->right = build(preorder, inorder, start-inStart+inRootIdx+1, end, 
                            inRootIdx+1, inEnd);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())   
            return NULL;
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
