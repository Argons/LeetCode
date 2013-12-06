// Given a linked list, determine if it has a cycle in it.

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
            // n2 traverses twice as fast as n1, 
            // if a cycle exists, they will meet eventually.
            n2 = n2->next;
        }
        return false;
    }
};
