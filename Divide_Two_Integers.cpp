// Divide two integers without using multiplication, division and mod operator.

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((double)dividend);
        long long b = abs((double)divisor);

        long long ret = 0;
        while (a >= b) {
            long long c = b; 
            // minus divisor from dividend, divisor *2 each time,
            // ret(count) +(2^i) each time.
            // when divisor becomes greater than the remaining dividend,
            // reset divisor to the initial value and restart the process.
            for (int i = 0; a >= c; i++) {
                a -= c; 
                c <<= 1;
                ret += 1 << i;
            }
        }
        // the highest bit represents the sign of this integer.
        return ((dividend ^ divisor) >> 31) ? (-ret) : (ret);
    }
};
