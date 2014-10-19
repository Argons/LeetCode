# Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
# After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

# Definition for a binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        # use stack to level traversal the tree
        if not root: return
        stack = [None, root]
        pre, cur = None, None
        while stack:
            cur = stack.pop()
            if not cur:
                if not stack: break
                stack.insert(0, None)
                pre = None
            else:
                if cur.left: stack.insert(0, cur.left)
                if cur.right: stack.insert(0, cur.right)
                if pre: pre.next = cur
                pre = cur
