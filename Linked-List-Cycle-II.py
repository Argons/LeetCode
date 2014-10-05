class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        if not head or not head.next or not head.next.next: 
            return None
        fast, slow = head.next.next, head.next
        while fast:
            if fast is slow:
                while fast is not head:
                    fast = fast.next
                    head = head.next
                return head
            if not fast.next: return None
            fast, slow = fast.next.next, slow.next
        return None
