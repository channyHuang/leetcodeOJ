class Solution {
public:
    int kInversePairs(int n, int k) {
        if (n <= 1) return (k == 0 ? 1 : 0);
        if (k == 0) return 1;
        if (k > n * (n - 1) / 2) return 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

        dp[1][0] = 1;
        dp[2][0] = 1;
        dp[2][1] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i][0] = 1;
            dp[i][1] = i - 1;
            for (int j = 2; j <= k; j++) {
                if (j > i * (i - 1) / 2) break;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - (j >= i ? dp[i - 1][j - i] : 0);
                /*for (int x = 0; x <= j; x++) {
                    if (x >= i) break;
                    dp[i][j] += dp[i - 1][j - x];
                    dp[i][j] %= maxn;
                }*/
                dp[i][j] %= maxn;
                if (dp[i][j] < 0) dp[i][j] = (dp[i][j] + maxn) % maxn;
            }
        }
        return dp[n][k];
    }
private:
    int maxn = 1000000007;
};
