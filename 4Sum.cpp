// Given an array S of n integers, are there elements a, b, c, and d in S 
// such that a + b + c + d = target? Find all unique quadruplets in the 
// array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie,
// a ≤ b ≤ c ≤ d)  The solution set must not contain duplicate quadruplets.

// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
//  (-1,  0, 0, 1)
//  (-2, -1, 1, 2)
//  (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> item;
        if (num.empty())
            return ret;
        sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i-1])  // avoid duplicates
                continue;
            for (int j = num.size()-1; j > i; j--) {
                if (j < num.size()-1 && num[j] == num[j+1])  // ditto
                    continue;
                int start = i + 1, end = j - 1;
                while (start < end) {
                    int sum = num[i] + num[j] + num[start] + num[end];
                    if (start > i+1 && num[start] == num[start-1]) {
                        start++;
                    } else if (end < j-1 && num[end] == num[end+1]) {
                        end--;
                    } else {
                        if (sum == target) {
                            item.push_back(num[i]);
                            item.push_back(num[start]);
                            item.push_back(num[end]);
                            item.push_back(num[j]);
                            ret.push_back(item);
                            item.clear();
                            start++;
                            end--;
                        } else if (sum < target) {
                            start++;
                        } else {
                            end--;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
