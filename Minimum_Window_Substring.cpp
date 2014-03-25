// Given a string S and a string T, find the minimum window in S which 
// will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, 
// return the emtpy string "".
// If there are multiple such windows, you are guaranteed that there 
// will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string S, string T) {
        int sLen = S.length();
        int tLen = T.length();
        if (sLen < tLen)
            return "";
        
        // hasFound   stores the total number of a character met so far,
        // needToFind stores the total number of a character in T.
        int hasFound[256] = {0};
        int needToFind[256] = {0};
        for (int i = 0; i < tLen; i++)
            needToFind[T[i]]++;

        int minWindowBegin = INT_MAX, minWindowEnd = INT_MAX;
        int minWindowLen = INT_MAX;
        int count = 0; // count total number of chars in T that has met in S

        // two pointers
        for (int begin = 0, end = 0; end < sLen; end++) {
            // skip characters not in T
            if (needToFind[S[end]] == 0) 
                continue;
            hasFound[S[end]]++;
            if (hasFound[S[end]] <= needToFind[S[end]])
                count++;

            // if window constraint is satisfied
            if (count == tLen) {
                // advance begin index forward as far as possible,
                // stop when window constraint no longer suffices.
                while (needToFind[S[begin]] == 0 ||
                       hasFound[S[begin]] > needToFind[S[begin]]) {
                    if (hasFound[S[begin]] > needToFind[S[begin]]) {
                        hasFound[S[begin]]--;
                    }
                    begin++;
                }

                // update minWindow if a shorter length is met
                int windowLen = end - begin + 1;
                if (windowLen < minWindowLen) {
                    minWindowBegin = begin;
                    minWindowEnd = end;
                    minWindowLen = windowLen;
                } 
            }
        } 
        return (count == tLen) ? S.substr(minWindowBegin, minWindowLen) : "";
    }
};
