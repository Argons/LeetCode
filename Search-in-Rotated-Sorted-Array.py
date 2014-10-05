# Suppose a sorted array is rotated at some pivot unknown to you beforehand.
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
# You are given a target value to search. If found in the array return its 
# index, otherwise return -1.

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        i, j = 0, len(A)-1
        while i <= j:
            mid = (i+j) / 2
            if A[mid] == target: return mid
            if A[mid] < A[i]:
                if A[mid] < target <= A[j]: i = mid + 1
                else: j = mid - 1
            else:
                if A[i] <= target < A[mid]: j = mid - 1
                else: i = mid + 1
        return -1
