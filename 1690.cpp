class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int len = stones.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        vector<int> sum(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            sum[i] = sum[i - 1] + stones[i - 1];
        }
        for (int s = 1; s < len; s++) {
            for (int i = 0; i < len; i++) {
                if (i + s >= len) break; 
                if (s == 1) {
                    dp[i][i + 1] = max(stones[i], stones[i + 1]);
                } else {
                    dp[i][i + s] = max(sum[i + s + 1] - sum[i + 1] - dp[i + 1][i + s], sum[i + s] - sum[i] - dp[i][i + s - 1]);
                }
            }
        }
        return dp[0][len - 1];
    }
};
