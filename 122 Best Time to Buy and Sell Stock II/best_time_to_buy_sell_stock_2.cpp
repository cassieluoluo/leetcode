/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Best Time to Buy and Sell Stock II
 *	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 *	Runtime: 8 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            profit += diff > 0 ? diff : 0;
        }
        return profit;
    }
};