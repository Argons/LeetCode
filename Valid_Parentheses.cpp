// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.
// The brackets must close in the correct order, 
// "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
    public:
    bool isValid(string s) {
        int len = s.length();
        if (len == 0)
            return true;
        if (len % 2 == 1)
            return false;
        map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        stack<char> st;
        for (int i = 0; i < len; i++) {
            if (st.empty())
                st.push(s[i]);
            else if (s[i] != m[st.top()])
                st.push(s[i]);
            else
                st.pop();
        }
        return st.empty();
    }
 };
