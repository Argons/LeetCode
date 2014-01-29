// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
// (ie, from left to right, then right to left for the next level and alternate between)

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its zigzag level order traversal as:
// [
//  [3],
//  [20,9],
//  [15,7]
// ]

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        if (root == NULL)   
            return result;

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
            } 
            else {
                level.push_back(current->val);
                if (current->left != NULL)
                    nodes.push(current->left);
                if (current->right != NULL)
                    nodes.push(current->right);
            }
        }

        // reverse the order of odd index level vectors
        for (int i = 1; i < result.size(); i += 2) {
            vector<int> temp(result[i]);
            result[i].clear();
            result[i].insert(result[i].end(), temp.rbegin(), temp.rend());
        }
        return result;
    }
};
