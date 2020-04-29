class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        if (len == 1) return stones[0];
        int sum = 0;
        int dp[len + 1][30005];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++) {
            sum += stones[i - 1];
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], (dp[i - 1][k] + stones[i - 1] > j ? dp[i - 1][k] : dp[i - 1][k] + stones[i - 1]));
                }
            }
        }
        return sum - 2 * dp[len][sum / 2];
    }
};
