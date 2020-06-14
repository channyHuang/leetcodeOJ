class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();
        vector<int> res = prices;
        for (int i = 0, j; i < len - 1; i++) {
            for (j = i + 1; j < len; j++) {
                if (prices[j] <= prices[i]) break;
            }
            if (j >= len) continue;
            res[i] -= prices[j];
        }
        return res;
    }
};
