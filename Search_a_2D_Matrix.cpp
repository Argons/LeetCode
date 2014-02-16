// Write an efficient algorithm that searches for a value in an m x n matrix. 

// This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// For example,
// Consider the following matrix:
// [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // O(log M + log N) = O(log M*N)
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = row*col - 1;
        while (low <= high) {
            int mid = (low+high) / 2;
            int item = matrix[mid/col][mid%col];
            if  (item == target)
                return true;
            else if (item < target)
                low = mid + 1;
            else if (item > target)
                high = mid - 1;
        }
        return false;
    }
};
