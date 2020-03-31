class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        int used = -prices[0];
        int obtain = 0;
        for (int i = 1; i < len; i++) {
            used = max(used, obtain - prices[i]);
            obtain = max(obtain, used + prices[i] - fee);
        }
        return obtain;
    }
};
