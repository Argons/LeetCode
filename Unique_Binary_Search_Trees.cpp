// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
// 1         3     3      2      1
//  \       /     /      / \      \
//   3     2     1      1   3      2
//  /     /       \                 \
// 2     1         2                 3

class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1, 0);
        num[0] = 1;
        if (n > 0) 
            num[1] = 1;
        // Catalan number: f(n) = (2n)! / n! * (n+1)!
        for (int i = 2; i < n+1; i++) {
            for (int j = 0; j < i; j++) {
                // variations = different left sub-trees * right sub-trees
                num[i] += num[j] * num[i-j-1]; 
            }
        }
        return num[n];
    }
};
