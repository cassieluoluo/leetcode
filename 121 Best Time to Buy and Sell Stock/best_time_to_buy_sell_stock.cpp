/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Best Time to Buy and Sell Stock
 *	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *	Runtime: 8 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int sell = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            sell = max(sell, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return sell;
    }
};