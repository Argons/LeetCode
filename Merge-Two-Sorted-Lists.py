# Merge two sorted linked lists and return it as a new list. 
# The new list should be made by splicing together the nodes of the first two lists.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        result = None
        if l1.val > l2.val:
            result = l2
            result.next = self.mergeTwoLists(l1, l2.next)
        else:
            result = l1
            result.next = self.mergeTwoLists(l1.next, l2)   
        return result
