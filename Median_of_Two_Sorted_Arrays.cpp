// There are two sorted arrays A and B of size m and n respectively. 
// Find the median of the two sorted arrays. 
// The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    int findKth(int a[], int m, int b[], int n, int k) {
        assert(a && b);
        if (m <= 0)  // if a is empty, return the kth item in b.
            return b[k-1];  
        if (n <= 0) 
            return a[k-1];  
        if (k <= 1) 
            return min(a[0], b[0]);   

        // separate A, B into 4 parts by A[mid_a] and B[mid_b],
        // there are 4 scenarios, each would discard one part from the arrays.
        if (b[n/2] >= a[m/2]) {
            if ((m/2 + n/2 + 1) >= k)  
                return findKth(a, m, b, n/2, k);  
            else  
                return findKth(a + (m/2 + 1), m - (m/2 + 1), b, n, k - (m/2 + 1));  
        } else {  
            if ((m/2 + n/2 + 1) >= k)  
                return findKth(a, m/2, b, n, k);  
            else  
                return findKth(a, m, b + (n/2 + 1), n - (n/2 + 1), k - (n/2 + 1));
        }
    }  

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 0) 
            return (findKth(A, m, B, n, (m+n)/2) + findKth(A, m, B, n, (m+n)/2 + 1)) / 2.0;
        else 
            return findKth(A, m, B, n, (m+n)/2 + 1);
    }
};
