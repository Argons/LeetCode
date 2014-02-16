// Given a linked list, remove the nth node from the end of list and return its head.

// For example,
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *a = head;
        ListNode *b = head;
        int i = 0;
        while (i < n) {
            a = a->next;
            i++;
        }
        if (a == NULL)
            return head->next;
        while (a->next != NULL) {
            b = b->next;
            a = a->next;
        }
        b->next = b->next->next;
        return head;
    }
};
