// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> table(256, -1);
        int i = 0, end = 0, maxLen = 0;
        while (end < s.length()) {
            if (table[s[end]] >= i) {
                i = index + 1;  // find duplicate within, reset start index.
            }
            table[s[end]] = end;
            maxLen = max(maxLen, end-i+1);
            end++;
        }
        return maxLen;
    }
};
