// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> table(256, -1);  // record position of chars
        int start = 0, end = 0, maxLen = 0;
        while (end < s.length()) {
            if (table[s[end]] >= start) {
                // if find duplicate within start and end, reset start index
                start = index + 1;  
            }
            table[s[end]] = end;
            end++;
            maxLen = max(maxLen, end-start);
        }
        return maxLen;
    }
};
