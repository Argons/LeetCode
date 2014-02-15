// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode *current = head;
        int length = 0;
        while (current != NULL) {
            length++;
            current = current->next;
        }

        ListNode *middle = head;
        for (int i = 0; i < length/2; i++) {
            middle = middle->next;  // the node in the middle won't be altered.
        }

        stack<ListNode *> s;
        current = middle->next;
        for (int i = length/2 + 1; i < length; i++) {
            s.push(current);    
            current = current->next;
        }
        middle->next = NULL;
        while (!s.empty()) {
            current = s.top();
            s.pop();
            current->next = head->next;
            head->next = current;
            head = current->next;
        }
    }
};
