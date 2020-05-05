class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        if (len == 1) return 0;
        int dp[2][len];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        for (int i = 1; i < len; i++) {
            dp[0][i] = len + 1;
            dp[1][i] = len + 1;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                dp[0][i] = min(dp[0][i], dp[0][i - 1]);
                dp[1][i] = min(dp[1][i], dp[1][i - 1] + 1);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                dp[0][i] = min(dp[0][i], dp[1][i - 1]);
                dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
            }
        }
        return min(dp[0][len - 1], dp[1][len - 1]);
    }
};
