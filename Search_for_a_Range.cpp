// Given a sorted array of integers, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        if (n == 0)
            return result;

        int start = 0;
        int end = n-1;
        while (start <= end) {
            int mid = (start+end)/2;
            if (A[mid] == target) {
                start = mid;
                end = mid;
                // Do check indices in case out of bounds.
                while (start-1 >= 0 && A[start-1] == target)    
                    start--;
                while (end+1 < n && A[end+1] == target)      
                    end++;  
                result[0] = start;
                result[1] = end;
                return result;
            }
            if (A[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return result;
    }
};
