// A message containing letters from A-Z is being encoded to numbers using 
// the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of 
// ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// The number of ways decoding "12" is 2.

class Solution {
public:
    int numDecodings(string s) {
        // dp[i] = dp[i-1] * I(s[i] != 0) + dp[i-2] * I(s[i-1, i] <= 26)
        // special case: '0'
        if (s.empty())
            return 0;
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != '0') {
                dp[i] = dp[i-1];
            }
            
            // e.g. s[i-1, i] = '30' or '00'
            if (s[i] == '0' && (s[i-1] > '2' || s[i-1] == '0'))
                return 0;
            
            // '10' <= s[i-1, i] <= '26'
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                if (i >= 2) {
                    dp[i] += dp[i-2];
                } else {
                    dp[i] += 1;
                }
            }
        }
        return dp[s.length()-1];
    }
};
