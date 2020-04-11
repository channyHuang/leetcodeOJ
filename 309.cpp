class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int cost[len];
        int make[len];
        cost[0] = -prices[0];
        make[0] = 0;
        cost[1] = max(-prices[0], -prices[1]);
        make[1] = max(make[0], cost[0] + prices[1]);
        for (int i = 2; i < len; i++) {
            cost[i] = max(cost[i - 1], make[i - 2] - prices[i]);
            make[i] = max(make[i - 1], cost[i - 1] + prices[i]);
        }
        return make[len - 1];
    }
};
