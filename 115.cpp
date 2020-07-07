class Solution {
public:
    int numDistinct(string s, string t) {
        int lenn = t.length();
        int leni = s.length();
        if (leni < lenn) return 0;
        if (lenn == 0) return 1;
        long long dp[lenn][leni];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = (t[0] == s[0] ? 1 : 0);
        for (int i = 1; i < leni; i++) {
            dp[0][i] = (t[0] == s[i] ? dp[0][i - 1] + 1 : dp[0][i - 1]);
        }
        for (int i = 1; i < lenn; i++) {
            for (int j = i; j < leni; j++) {
                dp[i][j] = (t[i] == s[j] ? dp[i - 1][j - 1] + dp[i][j - 1] : dp[i][j - 1]);
            }
        }
        return dp[lenn - 1][leni - 1];
    }
};
