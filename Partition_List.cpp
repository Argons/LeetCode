// Given a linked list and a value x, partition it such that 
// all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return NULL;

        vector<int> greater;
        ListNode *current = head;
        ListNode *change = head;
        while (current != NULL) {
            if (current->val < x) {
                change->val = current->val;
                change = change->next;
            }
            else
                greater.push_back(current->val);
            current = current->next;
        }
        for (int i = 0; i < greater.size(); i++) {
            change->val = greater[i];
            change = change->next;
        }
        return head;
    }
};
