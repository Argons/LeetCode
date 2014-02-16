// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. 
// You may not modify the values in the list, only nodes itself can be changed.

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *current = head->next;
        ListNode *next = head->next->next;
        head->next = next;
        current->next = head;
        head = current;
        head->next->next = swapPairs(next);
        return head;
    }
};
