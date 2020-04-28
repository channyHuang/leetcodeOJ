class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int len = A.size();
        int sum[len];
        sum[0] = A[0];
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i - 1] + A[i];
        }
        if (K == 1) return sum[len - 1] * 1.0 / len;
        if (K == len) return sum[len - 1];
        double dp[len][K + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            dp[i][1] = sum[i] * 1.0 / (i + 1);
            for (int j = 2; j <= min(K, i + 1); j++) {
                for (int k = j - 2; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + (sum[i] - sum[k]) * 1.0 / (i - k));
                }
            }
        }
        return dp[len - 1][K];
    }
};
