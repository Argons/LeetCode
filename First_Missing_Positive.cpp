// Given an unsorted integer array, find the first missing positive integer.

// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.

// Your algorithm should run in O(n) time and uses constant space.

class Solution {
public:
    int firstMissingPositive(int A[], int n) {  // place integer i+1 at A[i]
        for (int i = 0; i < n; i++) {
            if (A[i] < n && A[i] > 0) {  // boundary check first
                if (A[i] != A[A[i]-1]) {  // do not change the correct item
                    swap(A[i], A[A[i]-1]);
                    i--;  // see if the swapped item needs alternation
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i+1)
                return i+1;  // return the first missing item
        }
        return n+1;  // if contains all integers from 1 to n, return n+1.
    }
};
