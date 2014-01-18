// Given a singly linked list where elements are sorted in ascending order, 
// convert it to a height balanced BST.

class Solution {
public:
    // don't forget '&' in parameter 'root', since treenodes are referenced.
    void build(TreeNode *&root, vector<int> &list, int start, int end)
    {
        if (start > end)
            return;
        int mid = (start+end) / 2;
        root = new TreeNode(list[mid]);
        if (start == end)
            return;
        build(root->left, list, start, mid-1);
        build(root->right, list, mid+1, end);
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *current = head;
        TreeNode *root;
        vector<int> list;
        while (current != NULL) {
            list.push_back(current->val);
            current = current->next;
        }
        build(root, list, 0, list.size()-1);
        return root;
    }
};
