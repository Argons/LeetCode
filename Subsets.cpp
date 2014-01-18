// Given a set of distinct integers, S, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.

// For example,
// If S = [1,2,3], a solution is:
// [
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
// ]

class Solution {
public:
    void traverse(vector<int> &S, int start, set<vector<int> > &result, vector<int> &item)
    {
        result.insert(item);
        if (start >= S.size())
            return;
        item.push_back(S[start]);
        traverse(S, start+1, result, item);
        item.pop_back();
        traverse(S, start+1, result, item);
    }

    vector<vector<int> > subsets(vector<int> &S) {
        set<vector<int> > res; // use 'set' to avoid duplicates in res.
        vector<vector<int> > result;
        if (S.size() == 0)
            return result;
        vector<int> item;
        sort(S.begin(), S.end()); // to keep item of ascending order.
        traverse(S, 0, res, item);

        for (set<vector<int> >::iterator iter = res.begin(); 
             iter != res.end(); iter++)
            result.push_back(*iter);
        return result;
    }
};

// Better solution:
vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > result(1);
    for (int i = 0; i < S.size(); i++) {
        int j = result.size();
        while (j > 0) {
            result.push_back(result[j]);
            result.back().push_back(S[i]);
            j--;
        }
    }
    return result;
}
