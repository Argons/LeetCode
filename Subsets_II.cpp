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

// without using 'set':
void traverse(vector<int> &s, int start, vector<vector<int> > &result, vector<int> &item)
{
    result.push_back(item);
    for (int i = start; i < s.size(); ++i) {
        if (i != start && s[i] == s[i-1])
            continue;  // to avoid duplicates
        item.push_back(s[i]);
        traverse(s, i+1, result, item);
        item.pop_back();
    }
}
vector<vector<int> > subsetsWithDup(vector<int> &S) 
{
    vector<vector<int> > result;
    vector<int> item;
    sort(S.begin(), S.end());
    traverse(S, 0, result, item);
    return result;
}

// without using recursion
vector<vector<int> > subsetsWithDup(vector<int> &S) 
{
    vector<vector<int> > result(1);
    sort(S.begin(), S.end());
    int unique = 0;
    for (int i = 0; i < S.size(); i++) {
        int size = result.size();
        if (i != 0 && S[i] == S[i-1]) {
            for (int j = unique; j < size; j++) {
                result.push_back(result[j]);
                result.back().push_back(S[i]); 
            }
            unique = size;
            continue;
        }
        unique = size;
        for (int j = 0; j < size; j++) {
            result.push_back(result[j]);
            result.back().push_back(S[i]);
        }
    }
    return result;
}
