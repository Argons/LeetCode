// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        // Fibinacci array
        int res1 = 1, res2 = 1;
        for (int i = 2; i <= n; i++) {
            int temp = res2;
            res2 += res1;
            res1 = temp;
        }
        return res2;
    }
};
