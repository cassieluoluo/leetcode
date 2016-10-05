class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), profit = INT_MIN;
        if (len < 2) return 0;
        int buy = prices[0], sell = prices[len - 1];
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        for (int i = 1; i < len; i++) {
            buy = min(buy, prices[i]);
            left[i] = max(left[i - 1], prices[i] - buy);
        }
        for (int j = len - 2; j >= 0; j--) {
            sell = max(sell, prices[j]);
            right[j] = max(right[j + 1], sell - prices[j]);
        }
        for (int k = 0; k < len; k++) {
            profit = max(profit, left[k] + right[k]);
        }
        return profit;
    }
}; // Author: XC
