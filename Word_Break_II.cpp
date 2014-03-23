// Given a string s and a dictionary of words dict, add spaces in s to 
// construct a sentence where each word is a valid dictionary word.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].

class Solution {
public:
    void getSentences(const string &s, const unordered_set<string> &dict, 
                      string &sentence, vector<string> &result,
                      int start, vector<bool> &check) {
        if (start == s.length()) {
            result.push_back(sentence.substr(1));
            return;
        }

        for (int i = start; i < s.length(); i++) {
            string sub = s.substr(start, i-start+1);
            if (check[i+1] && dict.find(sub) != dict.end()) {
                string temp = sentence;
                sentence += " " + sub;
                int curSolSize = result.size();
                getSentences(s, dict, sentence, result, i+1, check);
                if (result.size() == curSolSize) {  // prune the wrong answer
                    check[i+1] = false;  // the path starts with i+1 is dead.
                }
                sentence = temp;
            }   
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        string sentence;
        int len = s.length();
        vector<bool> possible(len+1, true);
        getSentences(s, dict, sentence, ret, 0, possible);
        return ret;
    }
};
