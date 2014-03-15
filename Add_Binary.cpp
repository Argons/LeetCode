// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int sum = 0;
        int i = a.size() - 1, j = b.size() - 1;
        int a_val = 0, b_val = 0;
        while (i >= 0 || j >= 0 || carry) {
            a_val = (i >= 0 ? a[i] - '0' : 0);
            b_val = (j >= 0 ? b[j] - '0' : 0);

            sum = a_val + b_val + carry;
            carry = sum / 2;
            sum %= 2;
            res.insert(0, 1, sum + '0');

            i = (i >= 0 ? --i : i);
            j = (j >= 0 ? --j : j);
        }
        return res;
    }
};
