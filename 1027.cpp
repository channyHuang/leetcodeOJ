class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();
        if (len == 2) return len;
        int dp[len][len];
        int res = 2;
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i < len; i++) {
            for (int x = i - 2; x >= 0; x--) {
                for (int y = i - 1; y > x; y--) {
                    if (A[y] + (A[y] - A[x]) * (dp[x][y] + 1) == A[i]) {
                        dp[x][y]++;
                    }
                    res = max(res, dp[x][y] + 2);
                }
            }
        }
        return res;
    }
};
