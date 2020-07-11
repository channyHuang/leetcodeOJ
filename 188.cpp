class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        if (k >= len / 2) return maxProfit(prices);
        //int dp[len + 1][k + 1][2];
        k = min(k, len / 2);
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        //memset(dp, 0, sizeof(dp));

        for (int x = 0; x <= k; x++) {
            dp[0][x][0] = 0;
            dp[0][x][1] = INT_MIN;
        }
        for (int i = 0; i < len; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }

        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i + 1][j][0] = max(dp[i][j][0], dp[i][j][1] + prices[i]);
                dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - prices[i]);
            }
        }

        int res = dp[len][0][0];
        for (int x = 1; x <= k; x++) {
            res = max(res, dp[len][x][0]);
        }
        return res;
    }

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
