class Solution {
public:
    int knightDialer(int N) {
        long long dp[N + 1][10];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < 10; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= N; i++) {
            dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % maxn;
            dp[i][1] = (dp[i - 1][6] + dp[i - 1][8]) % maxn;
            dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % maxn;
            dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % maxn;
            dp[i][4] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]) % maxn;
            dp[i][5] = 0;
            dp[i][6] = (dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0]) % maxn;
            dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % maxn;
            dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % maxn;
            dp[i][9] = (dp[i - 1][2] + dp[i - 1][4]) % maxn;
        }
        int res = 0;
        for (int i = 0; i < 10; i++) {
            res = (res + dp[N][i]) % maxn;
        }
        return res;
    }

private:
    int maxn = 1000000007;
};
