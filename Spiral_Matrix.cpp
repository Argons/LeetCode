// Given a matrix of m x n elements (m rows, n columns), 
// return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty())    
            return result;

        int startRow = 0, endRow = matrix.size()-1;
        int startCol = 0, endCol = matrix[0].size()-1;

        while (startRow < endRow && startCol < endCol) {
            for (int j = startCol; j < endCol; j++) {
                result.push_back(matrix[startRow][j]);
            }
            for (int i = startRow; i < endRow; i++) {
                result.push_back(matrix[i][endCol]);
            }
            for (int j = endCol; j > startCol; j--) {
                result.push_back(matrix[endRow][j]);
            }
            for (int i = endRow; i > startRow; i--) {
                result.push_back(matrix[i][startCol]);
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        if (startRow == endRow) {
            for (int j = startCol; j <= endCol; j++)
                result.push_back(matrix[startRow][j]);
        }
        else if (startCol == endCol) {
            for (int i = startRow; i <= endRow; i++)
                result.push_back(matrix[i][startCol]);
        }
        return result;
    }
};
