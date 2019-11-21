class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int res = 0;
        for (int i = 0; i < len - 1; i++) {
            //i in
            for (int j = i + 1; j < len; j++) {
                if (prices[j] <= prices[i]) continue;
                if (res < prices[j] - prices[i]) res = prices[j] - prices[i];
            }
        }
        return res;
    }
};
