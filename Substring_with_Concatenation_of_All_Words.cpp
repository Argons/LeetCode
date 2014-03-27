// You are given a string, S, and a list of words, L, that are all of the same length. 
// Find all starting indices of substring(s) in S that is a concatenation of each word 
// in L exactly once and without any intervening characters.

// For example, given:
// S: "barfoothefoobarman"
// L: ["foo", "bar"]
// You should return the indices: [0,9] (order does not matter).

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (S.empty() || L.empty() || L[0].empty())
            return ret;

        int strLen = S.length();
        int size = L.size(), len = L[0].length();
        int toLen = size * len;
        int count;

        map<string, int> countS; // record occurence of strings in S
        map<string, int> countL; // count occurence of strings in L
        for (int i = 0; i < size; i++) {
            countL[L[i]]++;
        }

        for (int i = 0; i <= strLen-toLen; i++) {
            countS.clear();
            string cur;
            int j = 0;
            for (; j < toLen; j += len) {
                cur = S.substr(i+j, len);
                if (countL.find(cur) == countL.end())
                    break;
                else {
                    countS[cur]++;
                    if (countS[cur] > countL[cur])
                        break;
                }
            }
            if (j == toLen) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
