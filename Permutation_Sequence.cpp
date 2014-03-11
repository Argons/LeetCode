// The set [1,2,3,…,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

class Solution {
public:
    int factorial(int n) {
        int ret = 1;
        while (n > 1) {
            ret *= n;
            n--;
        }
        return ret;
    }

    string getPermutation(int n, int k) {
        string ret = "";
        vector<bool> taken(n+1, false);
        while (n > 0) {
            // each digit leads (n-1)! permutations
            int factor = factorial(n-1);  
            int i = 1;
            while (k > factor) {
                while (taken[i]) {
                    i++;
                }
                i++;
                k -= factor;
            }
            while (taken[i]) {
                i++;
            }
            char digit = '0' + i;
            ret += digit;
            taken[i] = true;
            n--;
        }
        return ret;
    }
};
