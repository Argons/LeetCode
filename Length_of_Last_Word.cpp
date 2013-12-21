// Given a string s consists of upper/lower-case alphabets and empty space 
// characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// For example, Given s = "Hello World", return 5.


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int space = -1, index = 0;
        int endOfLastWord = -1, spacePreWord = space;
        while (s[index] != '\0') {
            if (s[index] == ' ')
                space = index;
            else {
                spacePreWord = space;
                endOfLastWord = index;
            }
            index++;
        }
        return endOfLastWord-spacePreWord;
    }
};
        
