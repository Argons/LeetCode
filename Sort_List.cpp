// Sort a linked list in O(n log n) time using constant space complexity.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
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

        head  = sortList(head);
        right = sortList(right);
        return mergeTwoLists(head, right);
    }
};

ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;

    // let one pointer traverse two steps once, the other one step,
    // thus when fast reaches the tail, slow shall be in the midst.
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = slow->next;
    slow->next = NULL;

    head = sortList(head);
    newHead = sortList(newHead);
    return mergeTwoLists(head, newHead);
}
