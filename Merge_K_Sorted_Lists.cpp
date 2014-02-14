// Merge k sorted linked lists and return it as one sorted list. 
// Analyze and describe its complexity.

class Solution {
public:
    // merge 2 lists: O(min(len(l1), len(l2))) 
    // merge K lists: O(total_length)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL & l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *merge;
        ListNode *head;
        if (l1->val < l2->val) {
            head = new ListNode(l1->val);
            l1 = l1->next;
        } 
        else {
            head = new ListNode(l2->val);
            l2 = l2->next;
        }
        merge = head;

        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                merge->next = l2;
                break;
            }
            if (l2 == NULL) {
                merge->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                merge->next = new ListNode(l1->val);
                merge = merge->next;
                l1 = l1->next;
            } 
            else {
                merge->next = new ListNode(l2->val);
                merge = merge->next;
                l2 = l2->next;
            }
        }
        return head;
    }
};\
