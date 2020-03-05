class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if (len <= 0 || amount < 0) return -1;
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        if (amount < coins[0]) return -1;
        
        int dp[amount + 1] = {0};

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < len; j++) {
                if (i - coins[j] < 0) break;
                if (i == coins[j]) {
                    dp[i] = 1;
                    break;
                }
                if (dp[i - coins[j]] != -1) {
                    if (dp[i] == 0) dp[i] = dp[i - coins[j]] + 1;
                    else dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
            if (dp[i] == 0) dp[i] = -1;
        }

        return dp[amount];
    }
};
