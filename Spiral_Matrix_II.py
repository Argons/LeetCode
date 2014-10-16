class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        if n == 0: return []
        matrix = [range(n) for i in range(n)]
        start = 1
        for i in range((n+1)/2):
            k = n - i*2 - 1
            if k == 0: matrix[i][i] = start
            for j in range(k):
                matrix[i][i+j] = start
                matrix[i+j][i+k] = start + k
                matrix[i+k][i+k-j] = start + k*2
                matrix[i+k-j][i] = start + k*3
                start += 1
            start += k*3
        return matrix
