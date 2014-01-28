// Implement next permutation, which rearranges numbers into 
// the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it 
// as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column 
// and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // record the index of last digit pair of ascending order.
        int index = -1;
        for (int i = num.size()-1; i > 0; i--) {
            if (num[i] > num[i-1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            sort(num.begin(), num.end());
            return;
        }
        
        // find the next greater digit of num[index-1] in 'num' since index
        // swap them, then reorder the sub-array of 'num' since num[index].
        int nextBigger = num[index];
        int idx = index;
        for (int i = index+1; i < num.size(); i++) {
            if (num[i] > num[index-1] && nextBigger > num[i]) {
                nextBigger = num[i];
                idx = i;
            }
        }
        swap(num[idx], num[index-1]);
        sort(num.begin()+index, num.end());
    }
};
