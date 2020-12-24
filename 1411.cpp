class Solution {
public:
    int numOfWays(int n) {
        vector<long long> dp[2];//ABA,ABC
        dp[0].resize(n, 1);
        dp[1].resize(n, 1);
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[1][i - 1] * 2 % maxn + dp[0][i - 1] * 3 % maxn;
            dp[0][i] %= maxn;
            dp[1][i] = dp[1][i - 1] * 2 % maxn + dp[0][i - 1] * 2 % maxn;
            dp[1][i] %= maxn;
        }
        return (dp[0][n - 1] + dp[1][n - 1]) * 6 % maxn;
    }

private:
    int maxn = 1000000007;
};
