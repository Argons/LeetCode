// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.
//
// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next || k <= 1) 
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;

        int i = 1;
        while (head != NULL) {
            if (i == k) {
                pre = reverse(pre, head->next);                
                head = pre->next;
                i = 0;
            } 
            else {
                head = head->next;   
            }
            i++;
        }
        return dummy.next;
    }

    ListNode *reverse(ListNode *pre, ListNode *next) {
        // return the last node of the reversed linked list,
        // i.e. the 'pre' node of next sub-list of k length.
        ListNode *last = pre->next;
        ListNode *current = pre->next->next;
        while (current != next) {
            last->next = current->next;
            current->next = pre->next;  // insert 'current' after 'pre'
            pre->next = current;
            current = last->next;
        }
        return last;
    }
};
