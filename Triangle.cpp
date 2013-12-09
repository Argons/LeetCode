// Given a triangle, find the minimum path sum from top to bottom. 
// Each step you may move to adjacent numbers on the row below.

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
	    int len = triangle.size();
        if (len == 0)
            return 0;
        int dp[len][len];
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < len; i++) {
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
            dp[i][i] = triangle[i][i] + dp[i-1][i-1];
        }

        int minimum = dp[len-1][0];
        for (int i = 1; i < len; i++) {
            minimum = min(minimum, dp[len-1][i]);
        }
        return minimum;
    }
};
