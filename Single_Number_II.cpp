// Given an array of integers, every element appears three times except for one. 
// Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. 
// Could you implement it without using extra memory?

class Solution {
    public:
        int singleNumber(int A[], int n) {
            int once = 0, twice = 0, threes = 0;
            for (int i = 0; i < n; i++) {        
                // use AND to indicate bits which contain 1 twice.
                twice |= once & A[i];  
                // use XOR to indicate bits which contain 1 once.
                once ^= A[i]; 
                // indicate bits which contain 1 thrice.
                threes = once & twice;

                // reset indicators once, twice, i.e. the bits 
                // which contain 1 thrice will be set to 0. 
                once  &= ~threes;  
                twice &= ~threes;
            }
            return once;
        }
};

// plain solution
int singleNumber(int A[], int n) {
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}
