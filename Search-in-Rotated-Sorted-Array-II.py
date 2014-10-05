# Follow up for "Search in Rotated Sorted Array":
# What if duplicates are allowed?
# Would this affect the run-time complexity? How and why?
# Write a function to determine if a given target is in the array.

class Solution:
    # @param A a list of integers
    # @param target an integer
    # @return a boolean
    def search(self, A, target):
        i, j = 0, len(A)-1
        while i <= j:
            mid = (i+j) / 2
            if A[mid] == target: return True
            if A[mid] > A[i]:
                if A[i] <= target < A[mid]: j = mid - 1
                else: i = mid + 1
            elif A[mid] < A[i]: 
                if A[mid] < target <= A[j]: i = mid + 1
                else: j = mid - 1
            else: 
                if A[mid] == A[j]: # cannot decide which region the target lies
                    i += 1
                    j -= 1
                else: i = mid + 1
        return False
