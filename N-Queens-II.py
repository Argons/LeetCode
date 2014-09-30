class Solution:
    # @return an integer
    def totalNQueens(self, n):
        if n <= 0: return 0
        if n == 1: return 1
        queenPos = [-1 for i in range(n)]
        self.res = 0
        self.putQueen(queenPos, 0, n)
        return self.res
    
    def putQueen(self, queenPos, row, n):
        if row == n:
            self.res += 1
            return
        for col in range(n):
            if self.check(queenPos, row, col, n):
                queenPos[row] = col
                self.putQueen(queenPos, row+1, n)
                queenPos[row] = -1
                
    def check(self, queenPos, row, col, n):
        if col in queenPos: return False
        for i in range(row):
            if row+col == i+queenPos[i]: return False
            if row-col == i-queenPos[i]: return False
        return True
