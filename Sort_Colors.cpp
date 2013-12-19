// Given an array with n objects colored red, white or blue, 
// sort them so that objects of the same color are adjacent, 
// with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent 
// the color red, white, and blue respectively.

class Solution {
public:
    void sortColors(int A[], int n) {
        if (n < 2)  return;
        int red = 0, white = red; blue = n-1;

        while (white <= blue) {
            if (A[white] == 0)
                swap(A[white++], A[red++]);
            else if (A[white] == 2)
                swap(A[white++], A[blue]);
            else
                white++;
        }
    }
};

