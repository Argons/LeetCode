// Given a string s, partition s such that every substring of the partition is 
// a palindrome. Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return
// [
//  ["aa","b"],
//  ["a","a","b"]
// ]

class Solution {
public:
    bool isPalindrome(const string &s) {
        int size = s.size();
        for (int i = 0; i < size/2; i++) {
            if (s[i] != s[size-1-i])
                return false;
        }
        return true;
    }

    void partition(string &s, int start, vector<vector<string> > &result,
                   vector<string> &item) {
        if (start >= s.size()) {
            result.push_back(item);
            return;
        }

        for (int i = 1; start+i <= s.size(); i++) {
            string str = s.substr(start, i);
            if (isPalindrome(str)) {
                item.push_back(str);
                partition(s, start+i, result, item);
                item.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> item;
        partition(s, 0, result, item);
        return result;
    }
};
