// Implement pow(x, n).

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (x == 0.)
            return 0.;
        if (n < 0) {
            n = -n;
            x = 1./x;
        }
        double half = pow(x, n/2);
        if ((n & 1) == 0)
            return half * half;
        return x * half * half;
    }
};
