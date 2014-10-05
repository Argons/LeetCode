class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        if not matrix: return
        m, n = len(matrix), len(matrix[0])
        first_row, first_col = False, False

		# set the first row and first col as indicators 
        for i in range(m):
            if matrix[i][0] == 0:
                first_col = True
                break
        for j in range(n):
            if matrix[0][j] == 0:
                first_row = True
                break
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if first_col:
            for i in range(m): matrix[i][0] = 0
        if first_row:
            for j in range(n): matrix[0][j] = 0
