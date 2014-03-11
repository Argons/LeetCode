// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

class Solution {
public:
    void reverseWords(string &s) {
        string ret = "";
        char *cstr = new char[s.length()+1];
        strcpy(cstr, s.c_str());  // convert string into c_string
        char *word = strtok(cstr, " ");  // split c_string into tokens
        while (word != NULL) {
            ret = word + ret;
            ret = " " + ret;
            word = strtok(NULL, " ");
        }
        if (ret.empty()) {  // s could be empty or only composed of spaces
            s = "";
            return;
        }
        s = ret.substr(1);
    }
};
