class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int len = piles.size();
        if (len == 1) return piles[0];
        if (len == 2) return piles[0] + piles[1];
        int dp[len + 1][len + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < len; i++) dp[len - 1][i] = piles[len - 1];
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            sum += piles[i];
            for (int j = 1; j < len; j++) {
                for (int k = 1; k <= min(len - i, j * 2); k++)
                    dp[i][j] = max(dp[i][j], sum - dp[i + k][max(j, k)]);
            }
        }
        return dp[0][1];
    }
};
