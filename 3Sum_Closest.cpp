// Given an array S of n integers, find three integers in S 
// such that the sum is closest to a given number, target. 
// Return the sum of the three integers. 
// You may assume that each input would have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        if (size < 3)
            return 0;

        sort(num.begin(), num.end());
        int closest = num[0]+num[1]+num[2];

        for (int i = 0; i < size-2; i++) {
            int start = i+1;
            int end = size-1;

            while (start < end) {
                int sum = num[i]+num[start]+num[end];
                if (sum == target)
                    return target;
                if (abs(closest-target) > abs(sum-target))
                    closest = sum;
                if (sum > target)
                    end--;
                else
                    start++;    
            }
        }
        return closest;
    }
};
