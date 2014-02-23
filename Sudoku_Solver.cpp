// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.

class Solution {
public:
    bool dfs(vector<vector<char> > &board, 
             vector<vector<bool> > &rowSel, 
             vector<vector<bool> > &colSel, 
             vector<vector<bool> > &gridSel, 
             int location) {
        if (location == 81) 
            return true;

        int row = location / 9;
        int col = location % 9;
        int grid = row / 3 * 3 + col / 3;

        if (board[row][col] != '.') 
            return dfs(board, rowSel, colSel, gridSel, location+1);

        for (int i = 1; i <= 9; i++) {
            if (!rowSel[row][i] && !colSel[col][i] && !gridSel[grid][i]) {
                rowSel[row][i] = colSel[col][i] = gridSel[grid][i] = true;
                board[row][col] = i + '0';
                if (dfs(board, rowSel, colSel, gridSel, location+1)) 
                    return true;
                board[row][col] = '.';
                rowSel[row][i] = colSel[col][i] = gridSel[grid][i] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > rowSel(10, vector<bool>(10, false));
        vector<vector<bool> > colSel = rowSel, gridSel = rowSel;
        for (int i = 0; i < 81; i++) {
            int row = i / 9;
            int col = i % 9;
            int grid = row/3 * 3 + col/3;
            if (board[row][col] != '.'){
                int num = board[row][col] - '0';
                rowSel[row][num] = colSel[col][num] = gridSel[grid][num] = true;
            }
        }
        dfs(board, rowSel, colSel, gridSel, 0);
    }
};
