class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int dp[len][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            int cnt1 = 0;
            for (int j = 0; j < strs[i].length(); j++) cnt1 += (strs[i][j] - '0');
            int cnt0 = strs[i].length() - cnt1;
            if (i == 0) {
                for (int j = cnt0; j <= m; j++) {
                    for (int k = cnt1; k <= n; k++) {
                        dp[0][j][k] = 1;
                    }
                }
            } else {
                for (int j = 0; j <= m; j++) {
                    for (int k = 0; k <= n; k++) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                        if (j >= cnt0 && k >= cnt1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - cnt0][k - cnt1] + 1);
                    }
                }
            }
        }
        return dp[len - 1][m][n];
    }
};
