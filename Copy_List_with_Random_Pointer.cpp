// A linked list is given such that each node contains an additional 
// random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur = head;

        // insert duplicate nodes
        while (cur != NULL) {
            RandomListNode *temp = new RandomListNode(cur->label);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }

        // copy random pointers
        cur = head;
        while (cur != NULL) {
            RandomListNode *temp = cur->next;
            if (cur->random != NULL)
                temp->random = cur->random->next;
            cur = temp->next;
        }
        
        // decouple two random lists
        RandomListNode *ret = (head == NULL ? NULL : head->next);
        cur = head;
        while (cur != NULL) {
            RandomListNode *temp = cur->next;
            cur->next = temp->next;
            if (temp->next != NULL)
                temp->next = temp->next->next;
            cur = cur->next;
        }
        return ret;
    }
};
