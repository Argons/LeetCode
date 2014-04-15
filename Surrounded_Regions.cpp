// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X

// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
public:
    void bfs(vector<vector<char> > &board, int x, int y) {
        board[x][y] = 'S'; // mark the un-surrounded item with 'S'
        queue<pair<int, int> > record;
        record.push(make_pair(x, y));

        while (!record.empty()) {
            int x = record.front().first;
            int y = record.front().second;
            record.pop();

            if (x - 1 >= 0 && board[x-1][y] == 'O') {
                board[x-1][y] = 'S';
                record.push(make_pair(x-1, y));
            }
            if (x + 1 < board.size() && board[x+1][y] == 'O') {
                board[x+1][y] = 'S';
                record.push(make_pair(x+1, y));
            }
            if (y - 1 >= 0 && board[x][y-1] == 'O') {
                board[x][y-1] = 'S';
                record.push(make_pair(x, y-1));
            }
            if (y + 1 < board[0].size() && board[x][y+1] == 'O') {
                board[x][y+1] = 'S';
                record.push(make_pair(x, y+1));
            }
        }
    }

    void solve(vector<vector<char> > &board) {
        if (board.empty())
            return;
        int row = board.size(), col = board[0].size();
        
        // check the edges for 'O', then start BFS from them
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][col-1] == 'O') {
                bfs(board, i, col-1);
            }
        }
        for (int j = 1; j < col-1; j++) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j);
            }
            if (board[row-1][j] == 'O') {
                bfs(board, row-1, j);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
