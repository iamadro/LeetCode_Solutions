class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, n = prices.size();
        int buy_at = 0, sell_at = -1; 
        int sell = -1, buy = prices[buy_at];

        // 3
        for (int i = 0; i < n; i++) {
            if (sell_at == -1 || prices[i] > sell) {
                sell = prices[i]; // 5
                sell_at = i; // 2
            } else if (prices[i] < buy) {
                buy = prices[i]; // 1
                buy_at = i; // 1
                sell_at = i; // 1
                sell = prices[i]; // 1
            }

            if (buy_at < sell_at) {
                maxProfit = max(maxProfit, sell - buy); // 4
            }

        }

        return maxProfit;
    }
};