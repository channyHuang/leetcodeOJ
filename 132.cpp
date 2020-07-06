class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        int res = len;

        bool dp[len][len];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i + 1 < len) dp[i][i + 1] = (s[i] == s[i + 1]);
        }

        for (int l = 2; l < len; l++) {
            for (int i = 0; i < len; i++) {
                if (i + l >= len) break;
                dp[i][i + l] = (dp[i + 1][i + l - 1] && s[i] == s[i + l]);
            }
        }

        int count[len];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < len; i++) {
            if (dp[0][i]) {
                count[i] = 1;
                continue;
            }
            count[i] = i + 1;
            for (int j = 1; j <= i; j++) {
                if (dp[j][i]) count[i] = min(count[i], count[j - 1] + 1);
            }
        }
        
        return count[len - 1] - 1;     
    }
};
