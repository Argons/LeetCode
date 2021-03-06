// Given a set of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.
// 
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// The solution set must not contain duplicate combinations.

// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

class Solution {
public:
    void dfs(vector<int> &candidates, int target, int start, vector<vector<int> > &result, vector<int> &item)
    {
        if (start >= candidates.size())
            return;
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(item);
            return;
        }
        
        item.push_back(candidates[start]);
        dfs(candidates, target-candidates[start], start, result, item);
        item.pop_back();
        dfs(candidates, target, start+1, result, item);
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if (candidates.size() == 0)
            return result;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, result, item);
        return result;
    }
};
