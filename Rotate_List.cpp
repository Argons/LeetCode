// Given a list, rotate the list to the right by k places, where k is non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *current = head;
        int i = 1, len = 0;
        while (current != NULL) {
            if (current->next == NULL) {
                current->next = head;  // circularly linked list
                len = i;
                i = 0;
                k = len - k % len;
            } 
            else if (len != 0 && i == k) { 
                break;  // re-traverse (len - k % len) steps from head
            }
            i++;
            current = current->next;
        }

        head = current->next;
        current->next = NULL;
        return head;
    }
};
