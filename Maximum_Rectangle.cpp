// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
// containing all ones and return its area.

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        
        // take every row as the plain of a histogram, 
        // compute the height on each column of each layer.
        // add an extra item at the end of each row.
        vector<vector<int> > hist(row, vector<int>(col+1, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0) {
                        hist[i][j] = 1;
                    } else {
                        hist[i][j] = hist[i-1][j] + 1;
                    }
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < row; i++) {
            int area = 0, j = 0;
            stack<int> s;
            
            // compute maximum rectangle area for each histogram, i.e. each row
            while (j <= col) {
                if (s.empty() || hist[i][s.top()] <= hist[i][j]) {
                    s.push(j);
                    j++;
                } else {
                    int temp = s.top();
                    s.pop();
                    area = max(area, hist[i][temp] * (s.empty() ? j : j-s.top()-1));
                }
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
