// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time 
// (ie, you must sell the stock before you buy again).

class Solution {
    public:
        int maxProfit(vector<int> &prices) 
        {
            if (prices.empty())
                return 0;
            int size = prices.size();
            int dfOne[size];
            int dfTwo[size];

            // dp[0...i] => dp[0...i+1]
            // dp[j+1...n] => dp[j...n]
            int MIN = prices[0];
            dpOne[0] = 0;
            for (int i = 1; i < size; i++) {
                MIN = min(prices[i], MIN);
                dpOne[i] = max(dpOne[i-1], prices[i] - MIN);
            }

            int MAX = prices[size-1];
            dpTwo[size-1] = 0;
            for (int i = size-2; i >= 0; i--) {
                MAX = max(prices[i], MAX);
                dpTwo[i] = max(dpTwo[i+1], MAX - prices[i]);
            }

            int result = 0;
            for (int i = 0; i < prices.size(); i++) {
                int profit = dpOne[i] + dpTwo[i];
                result = max(result, profit);
            }
            return result;
        }
};
