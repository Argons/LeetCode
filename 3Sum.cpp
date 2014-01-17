// Given an array S of n integers, are there elements a, b, c in S 
// such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order.
// The solution set must not contain duplicate triplets.
    
// For example, given array S = {-1 0 1 2 -1 -4},
// A solution set is:
//  (-1, 0, 1)
//  (-1, -1, 2)


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        int size = num.size();
        if (size == 0)
            return result;

        vector<int> item;
        sort(num.begin(), num.end());
        if (num[size-1] < 0)
            return result; 

        for (int i = 0; i < size-2; i++) {
            int target = 0 - num[i];
            int start = i+1;
            int end = size-1;

            if (num[i] > 0)
                break;
            
            // use two indicators to track the other two for one fixed item.
            while (start < end) {
                if (num[start] + num[end] == target) {
                    item.push_back(num[i]);
                    item.push_back(num[start]);
                    item.push_back(num[end]);
                    result.push_back(item);
                    item.clear();

                    start++;
                    end--;
                    while (start < end && num[start] == num[start-1])
                        start++;    // in case there are duplicates.
                    while (start < end && num[end] == num[end+1])
                        end--;
                } 
                else if (num[start] + num[end] < target)
                    start++;
                else
                    end--;
            }
            while (num[i] == num[i+1])
                i++;    // in case there are duplicates.
        }
        return result;
    }
};
