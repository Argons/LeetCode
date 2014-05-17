# Given an array and a value, remove all instances of that value in place and 
# return the new length. The order of elements can be changed. 
# It doesn't matter what you leave beyond the new length.

class Solution:
    def removeElement(self, A, elem):
        index = 0
        for i in range(len(A)):
            if A[i] is not elem:
                A[index] = A[i]
                index += 1
        return index
