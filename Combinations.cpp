// Given two integers n and k, return all possible combinations of 
// k numbers out of 1 ... n.
//
// For example, If n = 4 and k = 2, a solution is:
// [ [2,4],[3,4],[2,3],[1,2],[1,3],[1,4] ]


class Solution {
public:
    vector<vector<int> > combine(int n, int k) 
    {
        vector<vector<int> > result;
        vector<int> item;
        getCombined(n, k, 1, result, item);
        return result;
    }

    void getCombined(int n, int k, int kth, vector<vector<int> > &result, 
                     vector<int> &item) {
        if (item.size() == k) {
            result.push_back(item);
            return;
        }
        for (int i = kth; i <= n; i++) {
            item.push_back(i);
            getCombined(n, k, kth+1, result, item);
            item.pop_back();
        }
    }
};
