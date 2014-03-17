// Given a string S, find the longest palindromic substring in S. 
// You may assume that the maximum length of S is 1000, and there 
// exists one unique longest palindromic substring.

class Solution {
public:
    // O(N^2) time complexity
    string longestPalindrome(string s) {  
        // take each character in s as the midst of a palindrome,
        // then expend it towards both sides to count its length.
        int len = s.length();
        int maxLen = 0;
        string maxStr;
        for (int i = 0; i < len; i++) {
            int mid = i;
            int oddLen = 1, evenLen = 0;
            while (mid+oddLen < len && mid-oddLen >= 0 && 
                    s[mid+oddLen] == s[mid-oddLen]) {
                oddLen++;
            }
            if (2*oddLen-1 > maxLen) {
                maxLen = max(2*oddLen-1, maxLen);
                maxStr = s.substr(mid-oddLen + 1, 2*oddLen - 1);
            }

            while (mid+evenLen < len && mid-1-evenLen >= 0 && 
                    s[mid+evenLen] == s[mid-1-evenLen]) {
                evenLen++;
            }
            if (2*evenLen > maxLen) {
                maxLen = max(2*evenLen, maxLen);
                maxStr = s.substr(mid-evenLen, 2*evenLen);
            }

            evenLen = 0;
            while (mid+1+evenLen < len && mid-evenLen >= 0 && 
                    s[mid+1+evenLen] == s[mid-evenLen]) {
                evenLen++;  
            }
            if (2*evenLen > maxLen) {
                maxLen = max(2*evenLen, maxLen);
                maxStr = s.substr(mid-evenLen + 1, 2*evenLen);
            }
        }
        return maxStr;
    }
};
