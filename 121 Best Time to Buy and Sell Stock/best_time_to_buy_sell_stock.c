int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int buy = prices[0], sell = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] - buy > sell) sell = prices[i] - buy;
        if (prices[i] < buy) buy = prices[i];
    }
    return sell;
} // Author: Xinyu Chen