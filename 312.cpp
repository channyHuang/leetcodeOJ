class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> score(len + 2, 0);
        score[0] = score[len + 1] = 1;
        for (int i = 1; i <= len; i++) score[i] = nums[i - 1];
        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
        for (int j = 2; j < len + 2; j++) {
            for (int i = 0; i < len + 2; i++) {
                if (i + j >= len + 2) break;
                for (int k = i + 1; k < i + j; k++) {
                    int tmp = dp[i][k] + dp[k][i + j] + score[i] * score[k] * score[i + j];
                    dp[i][i + j] = max(dp[i][i + j], tmp);
                }
            }
        }
        return dp[0][len + 1];
    }
};
