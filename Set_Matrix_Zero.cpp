// Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
// Do it in place.

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool isZeroRow[row];
        bool isZeroCol[col];
        for (int j = 0; j < col; j++)
            isZeroCol[j] = false;
        for (int i = 0; i < row; i++) {
            isZeroRow[i] = false;
            for (int j = 0; j < col; j++) {
                if (!matrix[i][j]) {
                    isZeroRow[i] = true;
                    isZeroCol[j] = true;
                }
            }
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (isZeroRow[i] || isZeroCol[j]) 
                    matrix[i][j] = 0;
    }
};
