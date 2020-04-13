class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        int res = 1;
        for (int i = len - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if (res < dp[i][j]) res = dp[i][j];
            }
        }
        return res;
    }
};
