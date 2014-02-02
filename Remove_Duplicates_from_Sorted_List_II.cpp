// Given a sorted linked list, delete all nodes that have duplicate numbers, 
// leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

class Solution {
public: 
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head->next;
        if (head->val == p->val) {
            while (p != NULL && head->val == p->val) {
                p = p->next;
            }
            return deleteDuplicates(p);
        }
        head->next = deleteDuplicates(head->next);
        return head;    
    }
};

// without recursion
ListNode *deleteDuplicates(ListNode *head) 
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode preHead(0);
    preHead.next = head;
    ListNode *pre = &preHead, *current = head;

    while (current != NULL) {
        int value = current->val;
        if (current->next != NULL && current->next->val == value) {
            while (current != NULL && current->val == value) {
                pre->next = current->next;
                current = current->next;
            }
        } 
        else {
            pre = current;
            current = current->next;
        }
    }
    return preHead.next;
}
