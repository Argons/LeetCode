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
            int mins[size];
            int maxs[size];

            // dp[0...i] => dp[0...i+1]
            // dp[j+1...n] => dp[j...n]
            mins[0] = prices[0];
            for (int i = 1; i < size; i++) {
                mins[i] = min(mins[i-1], prices[i]);
            }
            dpOne[0] = 0;
            for (int i = 1; i < size; i++) {
                dpOne[i] = max(dpOne[i-1], prices[i] - mins[i]);
            }
            maxs[size-1] = prices[size-1];
            for (int i = size-2; i >= 0; i--) {
                maxs[i] = max(maxs[i+1], prices[i]);
            }
            dpTwo[size-1] = 0;
            for (int i = size-2; i >= 0; i--) {
                dpTwo[i] = max(dpTwo[i+1], maxs[i] - prices[i]);
            }
            
            int result = 0;
            for (int i = 0; i < prices.size(); i++) {
                int profit = dpOne[i] + dpTwo[i];
                result = max(result, profit);
            }
            return result;
        }
};
