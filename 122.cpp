class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pos = 0;
        int len = prices.size();
        int res = 0;
        while (pos < len - 1 && prices[pos + 1] <= prices[pos]) pos++;
        if (pos >= len - 1) return 0;
        for (int i = pos + 1; i < prices.size(); i++) {
            if (prices[i] > prices[pos]) {
                res += prices[i] - prices[pos];
                pos = i;
            } else if (prices[i] < prices[pos]) {
                pos = i;
            }
        }
        return res;
    }
};
