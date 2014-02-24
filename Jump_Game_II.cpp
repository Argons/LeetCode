// Given an array of non-negative integers, you are initially positioned
// at the first index of the array.
// Each element in the array represents your maximum jump length at that 
// position.
// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]
// The minimum number of jumps to reach the last index is 2. 
// (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

class Solution {
public:
    // Greedy ALgorithm
    int jump(int A[], int n) {
        int jump = 0;
        int maxReach = 0, curReach = 0;
        for (int i = 0; i < n; i++) {
            if (i > curReach) {
                curReach = maxReach;
                jump++;
            }
            maxReach = max(maxReach, i+A[i]);
        }
        return jump;
    }

    // Dynamic Programming(Time Limit Exceeded)
    int jump(int A[], int n) {
        vector<int> leap(n, n);
        leap[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j <= i+A[i] && j < n; j++) {
                leap[j] = min(leap[j], 1+leap[i]);
            }
        }
        return leap[n-1];
    }
};
