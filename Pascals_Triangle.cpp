// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return
// [
//  [1],
//  [1,1],
//  [1,2,1],
//  [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > result;
            if (numRows == 0)
                return result;

            vector<int> init(1, 1);
            result.push_back(init);
            for (int i = 1; i < numRows; i++) {
                vector<int> row(1, 1);
                for (int j = 1; j < i; j++) {
                    int current = result[i-1][j-1] + result[i-1][j];
                    row.push_back(current);
                }
                row.push_back(1);
                result.push_back(row);
            }
            return result;
        }
};
