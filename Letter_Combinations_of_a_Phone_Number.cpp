// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10];
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        vector<string> result(1, "");
        for (int i = 0; i < digits.size(); i++) {
            string letters = mapping[digits[i]-'0'];
            int curSize = result.size();
            vector<string> duplicate(result);
            
            // Note that when try to concatenate a duplicate of the vector,
            // Do not use iterators of itself but the duplicate's.
            for (int j = 1; j < letters.size(); j++) {
                result.insert(result.end(), duplicate.begin(), duplicate.end());
            }

            for (int j = 0; j < letters.size(); j++) {
                char cur = letters[j];
                for (int k = 0; k < curSize; k++) {
                    result[k + j * curSize] += cur;
                }
            }
        }
        return result;
    }
};
