// Given a number represented as an array of digits, plus one to the number.

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int carry = 1;
        for (int i = size-1; i >= 0; i--) {
            int sum = digits[i] + carry;
            if (sum == 10) {
                digits[i] = 0;
                carry = 1;
            } 
            else {
                digits[i] = sum;
                carry = 0;
                break;
            }
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
