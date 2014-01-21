// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())
            return 0;
        sort(num.begin(), num.end());

        int maxLength = 1; // record the current maximum length
        int len = 1;       // record the length of current consecutive sequence

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i-1]) // do nothing with duplicates
                continue;
            if (num[i] == num[i-1]+1)
                len++;
            else {
                maxLength = max(maxLength, len);
                len = 1;
            }
        }
        maxLength = max(maxLength, len);
        return maxLength;
    }
};

// use hash table, O(n) time complexity
int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> s;
    int maxlen = 0;
    for (vector<int>::iterator it = num.begin(); it != num.end(); it++) 
        s[*it] = 1;

    // each element in the array can be accessed at most twice,
    // therefore the amortized running time is O(n).
    for (vector<int>::iterator it = num.begin(); it != num.end(); it++) {
        if (s[*it] == 1) {
            s[*it] = 0;
            int len = 1;
            int left  = *it - 1;
            int right = *it + 1;

            while (s.find(left) != s.end() && s[left]) {
                s[left--] = 0;
                len++;
            }
            while (s.find(right) != s.end() && s[right]) {
                s[right++] = 0;
                len++;
            }
            maxlen = maxlen < len ? len : maxlen;
        }
    }
    return maxlen;
}
