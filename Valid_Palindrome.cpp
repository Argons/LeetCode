// Given a string, determine if it is a palindrome, considering 
// only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        int i = 0, j = s.size()-1;
        while (i < j) {
            char char_i = s[i];
            char char_j = s[j];
            if (!isalnum(char_i)) {
                i++;
                continue;
            }
            if (!isalnum(char_j)) {
                j--;
                continue;
            }
            if (isdigit(char_i) && char_i != char_j)
                return false;
            if (isalpha(char_i) && tolower(char_i) != tolower(char_j))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
