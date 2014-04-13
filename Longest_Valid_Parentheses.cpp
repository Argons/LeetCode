// Given a string containing just the characters '(' and ')', find the length 
// of the longest valid (well-formed) parentheses substring.  

// For "(()", the longest valid parentheses substring is "()", which has length
// = 2.  
// Another example is ")()())", where the longest valid parentheses substring 
// is "()()", which has length = 4.

class Solution {
public:
    int longestValidParentheses(const string &s) {
        int maxLen = 0;
        vector<int> dp(s.length(), 0);
        for (int i = s.size()-2; i >= 0; i--) {
            if (s[i] == '(') {
                int j = i+1 + dp[i+1];
                if (j < s.size() && s[j] == ')') {
                    dp[i] = dp[i+1] + 2; // "(())j"
                    if (j + 1 < s.size()) {
                        dp[i] += dp[j+1]; // "()j(())"
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
