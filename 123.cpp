class Solution {
public:
    int maxProfit(vector<int> prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int k = 2;
        int dp[len + 1][k + 1][2];
        memset(dp, 0, sizeof(dp));

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

        return max(dp[len][1][0], dp[len][2][0]);
    }
};
