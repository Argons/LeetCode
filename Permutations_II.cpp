// Given a collection of numbers that might contain duplicates, 
// return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

class Solution {
public:
    void permute(vector<int> &num, vector<bool> &used, 
                 vector<vector<int> > &result, 
                 vector<int> &item) {
        if (item.size() == num.size()) {
            result.push_back(item);
            return;
        }

        for (int i = 0; i < num.size(); i++) {
            // to avoid duplicate items, num[i] cannot be pushed into item
            // if the same number before is not used.
            if (used[i] || (i != 0 && num[i] == num[i-1] && !used[i-1]))
                continue;
            item.push_back(num[i]);
            used[i] = true;
            permute(num, used, result, item);
            item.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> item;
        vector<bool> used(num.size(), false);
        sort(num.begin(), num.end());
        permute(num, used, result, item);
        return result;
    }
};
