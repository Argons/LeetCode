// Given a sorted linked list, delete all duplicates such that each element appear only once.
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <set>
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL)
        	return NULL;
        set<int> table; // store all unique items in the list in a lookup table.
        ListNode *current = head;
        table.insert(current->val);
        while (current->next != NULL) {
        	if (table.find(current->next->val) != table.end()) {
            // if current->next is a duplicate, pointer 'current' remains the same node.
            	current->next = current->next->next;
            } else {
            	table.insert(current->next->val);
		        current = current->next; 
		    }
		return head;
	}
};
