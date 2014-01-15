// Given an array of integers, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return indices of the two numbers such that they add up to the target, 
// where index1 must be less than index2. Please note that your returned answers are not zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result(2);
        int size = numbers.size();

        for (int i = 0; i < size; i++) {
            int res = target - numbers[i];
            for (int j = i+1; j < size; j++) {
                if (numbers[j] == res) {
                    result[0] = i + 1;
                    result[1] = j + 1;
                    return result;
                }
            }
        }
    }
};
