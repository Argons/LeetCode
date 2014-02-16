// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        if (n == 0) 
            return matrix;
        int layer = n/2 + n%2;
        int item = 1;
        for (int i = 0; i < layer; i++) {
            if (i == n-1-i) {
                matrix[i][i] = item;
            }
            for (int j = i; j < n-1-i; j++) {
                matrix[i][j]         = item;
                matrix[j][n-1-i]     = item + n - 1 - 2 * i;
                matrix[n-1-i][n-1-j] = item + 2 * (n-1-2*i);
                matrix[n-1-j][i]     = item + 3 * (n-1-2*i);
                item++;
            }
            item += 3 * (n-1-2*i);
        }
        return matrix;
    }

    // cleaner solution
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));

        int start = 0, end = n-1;
        int num = 1;

        while (start < end) {
            for (int j = start; j < end; j++) {
                matrix[start][j] = num;
                num++;
            }
            for (int i = start; i < end; i++) {
                matrix[i][end] = num;
                num++;
            }
            for (int j = end; j > start; j--) {
                matrix[end][j] = num;
                num++;
            }
            for (int i = end; i > start; i--) {
                matrix[i][start] = num;
                num++;
            }
            start++;
            end--;
        }
        if (start == end)
            matrix[start][start] = num;
        return matrix;
    }
};
