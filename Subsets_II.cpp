// Given a collection of integers that might contain duplicates, S, 
// return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.

// For example,
// If S = [1,2,2], a solution is:
// [
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
// ]

class Solution {
public:
    void traverse(vector<int> &S, int start, set<vector<int> > &result, 
                  vector<int> &item) 
    {
        result.insert(item); // insert item before 'start' out of bounds check
        if (start >= S.size())
            return;
        item.push_back(S[start]);
        traverse(S, start+1, result, item);
        item.pop_back();
        traverse(S, start+1, result, item);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
        set<vector<int> > result; // use set to avoid duplicates.
        vector<vector<int> > res;
        if (S.size() == 0)
            return res;
        vector<int> item;
        sort(S.begin(), S.end());
        traverse(S, 0, result, item);

        for (set<vector<int> >::iterator iter = result.begin(); 
                iter != result.end(); iter++)
            res.push_back(*iter);
        return res;
    }
};
