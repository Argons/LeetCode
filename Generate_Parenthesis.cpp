//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0)
            generator(result, "", 0, 0, n);
        return result;
    }
    void generator(vector<string> &res, string s, int left, int right, int n) {
        if (left == n) {
            // enough left parenthesis, fill up the right parenthesis.
            res.push_back(s.append(n-right, ')'));
            return;
        }
        generator(res, s+'(', left+1, right, n);
        if (left > right) {
            generator(res, s+')', left, right+1, n);
        }
    }
};
