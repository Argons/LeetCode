// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode rhead(0);
        rhead.next = head;

        ListNode *preM, *prev = &rhead;
        for (int i = 1; i <= n; i++) {
            if (i <= m) {
                if (i == m) 
                    preM = prev;
                prev = head;
                head = head->next;
            } 
            else {
                prev->next = head->next;
                head->next = preM->next;
                preM->next = head;
                head = prev->next;
            }
        }
        return rhead.next;
    }
};
