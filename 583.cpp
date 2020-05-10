class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        int dp[len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= max(len1, len2); i++) {
            if (i <= len1) dp[i][0] = i;
            if (i <= len2) dp[0][i] = i;
        }
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j];
                else {
                    dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 2);
                }
            }
        }
        return dp[len1][len2];
    }
};
