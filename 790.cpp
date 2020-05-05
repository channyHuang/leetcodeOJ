class Solution {
public:
    int numTilings(int N) {
        if (N == 1) return 1;
        long long dp[3][N + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1; 
        dp[0][2] = 2;
        dp[1][2] = 1;
        dp[2][2] = 1;
        for (int i = 3; i <= N; i++) {
            dp[0][i] = (dp[0][i - 1] + dp[0][i - 2] + dp[1][i - 1] + dp[2][i - 1]) % maxn;
            dp[1][i] = (dp[0][i - 2] + dp[2][i - 1]) % maxn;
            dp[2][i] = (dp[0][i - 2] + dp[1][i - 1]) % maxn;
        }
        return dp[0][N];
    }

private:
    int maxn = 1000000007;
};
