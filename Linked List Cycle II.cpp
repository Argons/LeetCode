// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
    // detect if a cycle exists in the list.
        if (head == NULL || head->next == NULL)
            return false;
            
        ListNode *n1 = head;
        ListNode *n2 = head->next;
        while (n2 != NULL) {
            if (n1 == n2)
                return true;
            n1 = n1->next;
            n2 = n2->next;
            if (n2 == NULL)
                break;
            n2 = n2->next;
        }
        return false;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if (!hasCycle(head))
            return NULL;
            
        ListNode *a = head;
        ListNode *b = head;
        while (b->next != NULL) {
            a = a->next;
            b = b->next->next;
            // n1, n2 will meet at the node n-k steps to the start/end node of cycle, 
            // n = perimeter of cycle, k = steps of the head to the beginning of cycle.
            if (a == b)
                break;
        }
        if (b->next == NULL)
            return NULL;
        a = head;
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
