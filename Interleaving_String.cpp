// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
    public:
        // DP, O(N^2) extra space
        bool isInterleave(string s1, string s2, string s3) {
            if(s3.size() != s1.size() + s2.size())
                return false;

            vector<vector<bool> > match(s1.size()+1, 
                                        vector<bool>(s2.size()+1, false));

            // initialize the first row and the first column
            match[0][0] = true;
            for (int l1 = 1; l1 <= s1.size(); l1++) {
                if (s1[l1-1] == s3[l1-1]) {
                    match[l1][0] = true;
                } else 
                    break;
            }
            for (int l2 = 1; l2 <= s2.size(); l2++) {
                if (s2[l2-1] == s3[l2-1]) {
                    match[0][l2] = true;
                } else 
                    break;
            }

            // dp[i][j] = dp[i-1][j] || dp[i][j-1]
            for (int l1 = 1; l1 <= s1.size(); l1++) {
                for (int l2 = 1 ; l2 <= s2.size() ; l2++) {
                    if (s1[l1-1] == s3[l1+l2-1]) {
                        match[l1][l2] = match[l1-1][l2] || match[l1][l2];
                    }
                    if (s2[l2-1] == s3[l1+l2-1]) {
                        match[l1][l2] = match[l1][l2-1] || match[l1][l2];
                    }
                }
            }
            return match[s1.size()][s2.size()];
        }
};
