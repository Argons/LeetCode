// Given a string s, partition s such that every substring of the partition is 
// a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 
// 1 cut.

class Solution {
public:
    int minCut(const string &str){
        int len = str.length();
        int dp[len+1];
        bool palin[len][len];

        for (int i = 0; i <= len; i++) {
            dp[i] = len - i;
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                palin[i][j] = false;
            }
        }
        
        // use dp[i] to record the minCut of str[i:]
        // update dp[i] forward, update dp backwards
        for (int i = len-1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (str[i] == str[j] && (j-i < 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1] + 1);
                }
            }
        }
        return dp[0]-1;
    }
};
