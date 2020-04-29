class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d][target + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= min(f, target); i++) dp[0][i] = 1;
        for (int i = 1; i < d; i++) {
            for (int j = 1; j <= target; j++) {
                for (int k = 1; k <= f; k++) {
                    if (k > j) break;
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= maxn;
                }
            }
        }
        return dp[d - 1][target];
    }

private:
    int maxn = 1000000007;
};
