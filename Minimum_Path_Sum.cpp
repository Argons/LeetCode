// Given a m x n grid filled with non-negative numbers, find a path from top 
// left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int pathSum[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pathSum[i][j] = 0;

        pathSum[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            pathSum[i][0] = grid[i][0] + pathSum[i-1][0];
        for (int i = 1; i < n; i++)
            pathSum[0][i] = grid[0][i] + pathSum[0][i-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pathSum[i][j] = grid[i][j] + min(pathSum[i-1][j], 
                                                 pathSum[i][j-1]);
            }
        }
        return pathSum[m-1][n-1];
    }
};
