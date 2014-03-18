// Implement int sqrt(int x).
// Compute and return the square root of x.

class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        double n = 1.0;
        double eps = fabs(n*n - x);
        while (eps > 0.1) {
            n = (n + x/n) / 2;  // Newton's Method: n' = n - f(n)/f'(n)
            eps = fabs(n*n - x);
        }
        return int(n);
    }
};

// binary search
class Solution {
public:
    int sqrt(int x) {
        /// use long long type to avoid overflow
        long long start = 0, end = x/2 + 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (mid * mid == x)
                return mid;
            if (mid * mid > x) {
                end = mid - 1;
            } else {
                // square root of integer cannot be greater than the true value
                if ((mid+1) * (mid+1) > x)  
                    return mid;
                else
                    start = mid + 1;
            }
        }
        return mid;
    }
};
