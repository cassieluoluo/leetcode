public class Solution {
    public int MaxProfit(int[] prices) {
        if (prices.Length < 2) return 0;
        int buy = prices[0];
        int sell = 0;
        for (int i = 1; i < prices.Length; i++) {
            if (prices[i] - buy > sell) sell = prices[i] - buy;
            if (prices[i] < buy) buy = prices[i];
        }
        return sell;
    }
} // Author: XC
