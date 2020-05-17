class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        int len = coins.size();
        if (len == 0) return 0;
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
