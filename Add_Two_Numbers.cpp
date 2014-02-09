// You are given two linked lists representing two non-negative numbers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

class Solution {
public:
    void addToHead(ListNode *&head, int newData) {
        ListNode *newNode = new ListNode(newData);
        newNode->next = head;
        head = newNode;
    }

    ListNode *addReversedLists(ListNode *list1, ListNode *list2, int carry = 0) {
        if (list1 == NULL && list2 == NULL && carry == 0)
            return NULL;

        int data = carry;
        if (list1 != NULL)
            data += list1->val;
        if (list2 != NULL)
            data += list2->val;
        carry = data / 10;

        ListNode *result = addReversedLists((list1==NULL ? NULL : list1->next),
                                            (list2==NULL ? NULL : list2->next),
                                            carry);
        addToHead(result, data % 10);
        return result;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addReversedLists(l1, l2, 0);
    }
};
