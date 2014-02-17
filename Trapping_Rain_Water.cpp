// Given n non-negative integers representing an elevation map where the width 
// of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    // O(n) solution:
    // for each bar, find the max height bar on the left and right,
    // then this bar can hold min(max_left, max_right) - height.
    int trap(int A[], int n) {
        int i = 0, j = n-1;
        int volume = 0;        
        int k = 0;
        while (i < j) {
            if (A[i] <= A[j]) {
                k = i+1;
                while (A[i] > A[k]) {
                    volume += (A[i]-A[k]);
                    k++;
                }
                i = k;
            }
            else {
                k = j - 1;
                while (A[j] > A[k]) {
                    volume += (A[j]-A[k]);
                    k--;
                }
                j = k;
            }
        }   
        return volume;        
    }
};
