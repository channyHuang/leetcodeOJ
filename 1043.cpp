class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();  
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = A[0];
        for (int i = 1; i < len; i++) {
            int maxn = A[i];
            dp[i] = dp[i - 1] + A[i];
            for (int j = i - 1; j > i - K && j >= 0; j--) {
                if (A[j] > maxn ) maxn = A[j];
                dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + maxn * (i - j + 1));
            }
        }
        return dp[len - 1];
    }
};
