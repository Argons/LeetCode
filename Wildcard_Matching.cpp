// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).
// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s && !p) 
            return true;

        const char *m_p = NULL, *m_s = NULL;
        while (*s) {
            if (*p == '?' || *p == *s) {
                p++;
                s++;
            } else if (*p == '*') {
                while (*p == '*') {
                    p++;
                }
                if (*p == NULL) 
                    return true; 

                m_p = p; // store '*' pos for string and pattern
                m_s = s;
            } else if ((*p == NULL || *p != *s) && m_p) { // failed match
                s = ++m_s; // start over with the s next to m_s in string 
                p = m_p;  // reset p pos if the match failed and m_p is not NULL
            } else
                return false;
        }

        while (*p) {
            if (*p++ != '*')
                return false;
        }
        return true;
    }
};
