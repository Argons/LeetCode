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
            while (head->val == p->val) {
                p = p->next;
                if (p == NULL)
                    break;
            }
            return deleteDuplicates(p);
        }
        head->next = deleteDuplicates(head->next);
        return head;    
    }
};
