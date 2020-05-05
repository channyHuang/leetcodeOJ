class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;
        if (K == 1) {
            if (N >= W) return 1.0;
            return N * 1.0 / W;
        }
        if (K == N) return 1.0;
        double dp[K + W];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1.0;
        int stPos = 0;
        for (int i = stPos; i < K; i++) {
            for (int j = 1; j <= W; j++) {
                dp[i + j] += (dp[i] * 1.0 / W);
            }
        }
        double res = 0;
        for (int i = N; i < K + W; i++) {
            res += dp[i];
        }
        return res;
    }
};
