class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long long dp[n + 1][6];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                if (i == 0 || i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                for (int k = 0; k < 6; k++) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= maxn;
                }
                /*if (i >= rollMax[j]) {
                    dp[i][j] = (dp[i][j] + maxn - dp[i - rollMax[j]][j]) % maxn;
                    if (i > rollMax[j]) dp[i][j] = (dp[i][j] + dp[i - rollMax[j] - 1][j]) % maxn;
                }*/
                if (i - 1 > rollMax[j]) {
                    for (int k = 0; k < 6; k++) {
                        if (k == j) continue;
                        dp[i][j] = (dp[i][j] + maxn - dp[i - rollMax[j] - 1][k]) % maxn;
                    }
                } else if (i - 1 == rollMax[j]) {
                    dp[i][j] = (dp[i][j] + maxn - 1) % maxn;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < 6; i++) {
            res += dp[n][i];
            res %= maxn;
        }
        return res;
    }

private:
    int maxn = 1000000007;
};
