// Follow up for N-Queens problem.
// Now, instead outputting board configurations, 
// return the total number of distinct solutions.

class Solution {
public:
    bool check(vector<int> &queenPos, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (queenPos[i] == col) 
                return false; 
            if (abs(i-row) == abs(queenPos[i]-col)) 
                return false;
        }
        return true;
    }

    void putQueen(vector<int> &queenPos, int row, int n, int &result) {
        if (row == n) {
            result++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (check(queenPos, row, col, n)) {
                queenPos[row] = col;
                putQueen(queenPos, row+1, n, result);
                queenPos[row] = -1;
            }
        }
    }

    int totalNQueens(int n) {
        int result = 0;
        vector<int> queenPos(n, -1);
        putQueen(queenPos, 0, n, result);
        return result;
    }
};
