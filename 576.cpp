class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        long long dp[N + 1][m][n];
        memset(dp, 0, sizeof(dp));
        for (int r = 0; r < m; r++) {
            dp[1][r][0] += 1;
            dp[1][r][n - 1] += 1;
        }
        for (int r = 0; r < n; r++) {
            dp[1][0][r] += 1;
            dp[1][m - 1][r] += 1;
        }
        for (int s = 2; s <= N; s++) {
            for (int r = 0; r < m; r++)  {
                for (int c = 0; c < n; c++)  {
                    dp[s][r][c] = 0;
                    if (r > 0) dp[s][r][c] += dp[s - 1][r - 1][c];
                    if (r < m - 1) dp[s][r][c] += dp[s - 1][r + 1][c];
                    dp[s][r][c] %= 1000000007;
                    if (c > 0) dp[s][r][c] += dp[s - 1][r][c - 1];
                    if (c < n - 1) dp[s][r][c] += dp[s - 1][r][c + 1];
                    dp[s][r][c] %= 1000000007;
                }
            }
        }
        int res = 0;
        for (int r = 1; r <= N; r++) {
            res += dp[r][i][j];
            res %= 1000000007;
        }
        return res;
    }
};
