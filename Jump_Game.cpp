// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1)
            return true;
        int farthermost = A[0]; // record the right most index within reach
        for (int i = 1; i <= farthermost; i++) {
            if (i+A[i] > farthermost)
                farthermost = i+A[i];
            if (farthermost >= n-1)
                return true;
        }
        return false;
    }
};
