# Find the contiguous subarray within an array (containing at least one number)
# which has the largest product.

# For example, given the array [2,3,-2,4],
# the contiguous subarray [2,3] has the largest product = 6.

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        if not A:
            return 0
        if len(A) == 1:
            return A[0]
        curPos, curNeg, curMax = 1, 1, 0
        for a in A:
            if a > 0:
                curPos, curNeg = max(a, curPos*a), curNeg*a
                curMax = max(curMax, curPos)
            if a < 0:
                curPos, curNeg = curNeg*a, min(a, curPos*a)
                curMax = max(curMax, curPos)
            if a == 0:
                curPos, curNeg = 1, 1
        return curMax
