// Given a binary tree, return the level order traversal of its nodes' values. 
// (ie, from left to right, level by level)

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its level order traversal as:
// [
//  [3],
//  [9,20],
//  [15,7]
// ]

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        if (root == NULL)
            return result;
        queue<TreeNode*> nodes;
        // use data structure queue to implement level order traversal
        nodes.push(root);
        nodes.push(NULL);

        while (!nodes.empty()) {
            TreeNode *current = nodes.front();
            nodes.pop();
            // reach the end of one level
            if (current == NULL) {
                result.push_back(level);
                level.clear();
                // do check whether queue is empty before push 'NULL'
                if (nodes.empty())
                    break;
                nodes.push(NULL);
            }
            else {
                level.push_back(current->val);
                if (current->left != NULL)
                    nodes.push(current->left);
                if (current->right != NULL)
                    nodes.push(current->right);
            }
        }
        return result;
    }
};
