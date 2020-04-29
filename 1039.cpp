class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int len = A.size();
        if (len == 3) {
            return A[0] * A[1] * A[2];
        }
        long long dp[len][len];
        memset(dp, 0, sizeof(dp));
        for (int j = 2; j < len; j++) {
            for (int i = 0; i < len; i++) {
                dp[i][(i + j) % len] = 2147483647;
                for (int k = (i + 1) % len; k < (i + j) % len; k = (k + 1) % len) {
                    dp[i][(i + j) % len] = min(dp[i][(i + j) % len], dp[i][k] + dp[k][(i + j) % len] + A[i] * A[k] * A[(i + j) % len]);
                }
            }
        }
        return dp[0][len - 1];
    }
};
