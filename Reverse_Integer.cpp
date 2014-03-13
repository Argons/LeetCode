/**
* Reverse digits of an integer.
* Example1: x = 123, return 321
* Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int n = abs(x);
        while (n) {
            result += result * 10 + n % 10;
            n /= 10;
        }
        if (x < 0)
            return -result;
        return result;
    }
};
