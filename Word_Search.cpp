// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, 
// where "adjacent" cells are those horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// For example,
// Given board =
// [
//  ["ABCE"],
//  ["SFCS"],
//  ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

class Solution {
public:
    bool dfs(vector<vector<char> > &board, string word, 
             int index, int row, int col, vector<vector<bool> > &visited) {
        if (index == word.length()) 
            return true;

        // check boundaries first
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if (visited[row][col])
            return false;
        if (board[row][col] != word[index])
            return false;
        visited[row][col] = true;
        bool ret = dfs(board, word, index+1, row-1, col, visited) ||
                   dfs(board, word, index+1, row+1, col, visited) ||
                   dfs(board, word, index+1, row, col-1, visited) ||
                   dfs(board, word, index+1, row, col+1, visited);
        visited[row][col] = false;
        return ret;
    }

    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<bool> > visited(board.size(), 
                                      vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
