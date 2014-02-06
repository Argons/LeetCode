// Given a collection of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// The solution set must not contain duplicate combinations.

// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 

class Solution {
public:
    void sumSets(vector<int> &num, int start, int target, 
                 vector<vector<int> > &result, vector<int> &item) {
        if (target == 0) {
            result.push_back(item);
            return;
        }
        if (target < 0 || start >= num.size())
            return;

        item.push_back(num[start]);
        sumSets(num, start+1, target-num[start], result, item);
        item.pop_back();
        while (num[start+1] == num[start])
            // if num[start] is invalid, the same num after shall pass as well.
            start++; 
        sumSets(num, start+1, target, result, item);
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int> > result;
        if (num.empty())
            return result;
        vector<int> item;
        sort(num.begin(), num.end());
        sumSets(num, 0, target, result, item);
        return result;
    }
};
