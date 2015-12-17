class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int last_buy, last_sell, buy = INT_MIN, sell = 0;
        for (auto price : prices) {
            last_buy = buy;
            buy = max(last_sell - price, last_buy);
            last_sell = sell;
            sell = max(last_buy + price, last_sell);
        }
        return sell;
    }
};