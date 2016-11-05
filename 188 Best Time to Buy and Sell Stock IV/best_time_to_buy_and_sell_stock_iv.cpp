// A DP solution
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size()/2) return greedySolver(prices);
        // Let sofar[i][j] denote the maximum profit in [0, j] with [0, i] transactions
        // Let prev_max_ending_with_buy denote the maximum profit in [0, j-1] with [0, i-1] transactions and ends with a buy
        int len = prices.size();
        int sofar[k+1][len];
        memset(sofar, 0, sizeof sofar);
        for (int i = 1; i <= k; i++) {
            int prev_max_ending_with_buy = -prices[0];
            for (int j = 1; j < len; j++) {
                sofar[i][j] = max(sofar[i][j-1], prev_max_ending_with_buy + prices[j]);
                prev_max_ending_with_buy = max(prev_max_ending_with_buy, sofar[i-1][j-1] - prices[j]);
            }
        }
        return sofar[k][len-1];
    }

    int greedySolver(vector<int>& prices) {
        int result = 0, len = prices.size();
        for (int i = 1; i < len; i++) {
            result += max(0, prices[i] - prices[i - 1]);
        }
        return result;
    }
};
// Author: Xiaowen Zhang
