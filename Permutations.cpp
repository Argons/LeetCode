// Given a collection of numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

class Solution {
    public:
        vector<vector<int> > permutation(vector<int> &num, int len)
        {
            vector<vector<int> > result;
            if (len == 0)
                return result;
            if (len == 1) {
                vector<int> perm;
                perm.push_back(num[0]);
                result.push_back(perm);
                return result;
            }

            vector<vector<int> > prev = permutation(num, len-1);
            for (int i = 0; i < prev.size(); i++) {
                for(int j = 0; j <= prev[i].size(); j++) {
                    vector<int> temp  = prev[i];
                    // insert the 'len-1'th item into every index
                    temp.insert(temp.begin()+j, num[len-1]);
                    result.push_back(temp);
                }
            }
            return result;
        }

        vector<vector<int> > permute(vector<int> &num) {
            return permutation(num, num.size());
        }
};
