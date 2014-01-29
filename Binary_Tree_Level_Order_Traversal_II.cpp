// Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
// (ie, from left to right, level by level from leaf to root)

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its bottom-up level order traversal as:
// [
//  [15,7]
//  [9,20],
//  [3],
// ]

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
        vector<int> level;

        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(NULL);

        while (!nodes.empty()) {
            TreeNode *current = nodes.front();
            nodes.pop();
            if (current == NULL) {
                result.push_back(level);
                level.clear();
                if (nodes.empty())
                    break;
                nodes.push(NULL);
            } else {
                level.push_back(current->val);
                if (current->left != NULL) 
                    nodes.push(current->left);
                if (current->right != NULL) 
                    nodes.push(current->right);
            }
        }
        // reverse level order
        for (int i = 0; i < result.size() / 2; i++) {
            swap(result[i], result[result.size()-i-1]);
        }
        return result;
    }
};
