// There are N children standing in a line. Each child is assigned a rating value.
// You are giving candies to these children subjected to the following requirements:
//  Each child must have at least one candy.
//  Children with a higher rating get more candies than their neighbors.
//  What is the minimum candies you must give?

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candyNum(ratings.size(), 1);
        
        // traverse forwards and backwards
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                candyNum[i] = candyNum[i-1] + 1;
            }
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candyNum[i] <= candyNum[i+1]) {
                candyNum[i] = candyNum[i+1] + 1;
            }
        }
        return accumulate(candyNum.begin(), candyNum.end(), 0);
    }
};
