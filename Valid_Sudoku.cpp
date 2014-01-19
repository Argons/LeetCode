// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, 
// where empty cells are filled with the character '.'

class Solution {
public:
    bool isValid(vector<char> &unit)
    {
        sort(unit.begin(), unit.end());
        for (int i = 1; i < unit.size(); i++)
            if (unit[i] == unit[i-1] && unit[i] != '.')
                return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        int size = board.size();
        vector<char> unit;
        // check rows
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                unit.push_back(board[i][j]);
            if (!isValid(unit))
                return false;
            unit.clear();
        }
        // check columns
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                unit.push_back(board[j][i]);
            if (!isValid(unit))
                return false;
            unit.clear();
        }
        // check sub-boxes
        for (int i = 0; i < size; i+=3) {
            for (int j = 0; j < size; j+=3) {
                unit.push_back(board[i][j]);
                unit.push_back(board[i][j+1]);
                unit.push_back(board[i][j+2]);
                unit.push_back(board[i+1][j]);
                unit.push_back(board[i+1][j+1]);
                unit.push_back(board[i+1][j+2]);
                unit.push_back(board[i+2][j]);
                unit.push_back(board[i+2][j+1]);
                unit.push_back(board[i+2][j+2]);

                if (!isValid(unit))
                    return false;
                unit.clear();
            }
        }
        return true;
    }
};
