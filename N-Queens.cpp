// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, 
// where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

class Solution {
    vector<vector<string> > result;

public:
    vector<string> getBoard(vector<int> &queenPos, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][queenPos[i]] = 'Q';
        }
        return board;  
    }

    bool check(vector<int> &queenPos, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (queenPos[i] == col) 
                return false; 
            if (abs(i-row) == abs(queenPos[i]-col)) 
                return false;
        }
        return true;
    }

    void putQueen(vector<int> &queenPos, int row, int n) {
        if (row == n) {
            result.push_back(getBoard(queenPos, n));
            return;
        }
        for (int col = 0; col < n; col++) {
            if (check(queenPos, row, col, n)) {
                queenPos[row] = col;
                putQueen(queenPos, row+1, n);
                queenPos[row] = -1;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        result.clear();
        vector<int> queenPos(n, -1);
        putQueen(queenPos, 0, n);
        return result;
    }
};
