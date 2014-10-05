class Solution:
    # @param A a list of integers
    # @return an integers
    def removeDuplicates(self, A):
        if len(A) <= 2: return len(A)
        i, j = 2, 1
        while i < len(A):
            if not (A[i] == A[j] and A[i] == A[j-1]):
                A[j+1] = A[i]
                i, j = i+1, j+1
            else: i += 1
        return j + 1
