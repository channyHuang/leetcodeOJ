class Solution {
public:
    int minInsertions(string s) {
        len = s.length();
        if (len <= 1) return 0;
        if (len == 2) return (s[0] == s[1] ? 0 : 1);
        //dp[i][j] = (s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i][j - 1] + 1, dp[i + 1][j] + 1))
        vector<vector<int>> dp(len, vector<int>(len, len - 1));
        for (int i = 0; i < len - 1; i++) {
            dp[i][i] = 0;
            dp[i][i + 1] = (s[i] == s[i + 1] ? 0 : 1);
        }
        for (int step = 2; step < len; step++) {
            for (int i = 0; i < len; i++) {
                if (i + step >= len) break;
                dp[i][i + step] = (s[i] == s[i + step] ? dp[i + 1][i + step - 1] : min(dp[i][i + step - 1] + 1, dp[i + 1][i + step] + 1));
            }
        }

        /*for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        return dp[0][len - 1];
    }

private:
    int len;
};
