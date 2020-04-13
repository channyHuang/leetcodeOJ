class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int len = arr.size();
        if (len == 2) return arr[0] * arr[1];
        int maxn[len][len];
        for (int i = 0; i < len; i++) {
            maxn[i][i] = arr[i];
            for (int j = i + 1; j < len; j++) {
                maxn[i][j] = max(maxn[i][j - 1], arr[j]);
            }
        }
        long long dp[len][len];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < len; j++) {
            for (int i = j - 1; i >= 0; i--) {
                dp[i][j] = 2147483647;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxn[i][k] * maxn[k + 1][j]);
                }
            }
        }
        return dp[0][len - 1];
    }
};
