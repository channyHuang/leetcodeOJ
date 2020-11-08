class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> sum(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                sum[i][j - 1] = sum[i - 1][j - 1] + dp[i - 1][j - 1];
                sum[i][j - 1] %= maxn;
                dp[i][j] = dp[i - 1][j] + sum[i][j - 1];
                dp[i][j] %= maxn;
            }           
        }
        return dp[n][k];
    }
private:
    int maxn = 1000000007;
};
