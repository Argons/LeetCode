// Sort a linked list in O(n log n) time using constant space complexity.

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        int len = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            cur = cur->next;
            len++;
        }
        cur = head;
        for (int i = 0; i < len/2-1; i++) {
            cur = cur->next;
        }
        ListNode *right = cur->next;
        cur->next = NULL;  // separate the list from the midst
        cur = head;

        cur   = sortList(cur);
        right = sortList(right);
        head = mergeLists(cur, right);
        return head;
    }

    ListNode* mergeLists(ListNode *l1, ListNode *l2) {
        ListNode *head;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val) {
            head = l1;
            head->next = mergeLists(l1->next, l2);
        }
        else {
            head = l2;
            head->next = mergeLists(l1, l2->next);
        }
        return head;
    }
};
