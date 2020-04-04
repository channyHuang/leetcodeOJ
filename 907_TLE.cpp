class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int len = A.size();
        if (len == 1) return A[0];
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = A[0];
        int minn = A[0];
        int idx = 0;
        int res = A[0];
        for (int i = 1; i < len; i++) {
            if (A[i] <= minn) {
                minn = A[i];
                idx = i;
                dp[i] = minn * (i + 1) % maxn;               
            } else {
                int curMin = A[i];
                int curIdx = i;
                dp[i] = (dp[i] + curMin) % maxn;
                for (int j = i - 1; j > idx; j--) {
                    if (A[j] < curMin) curMin = A[j];
                    dp[i] = (dp[i] + curMin) % maxn;
                }
                dp[i] = (dp[i] + minn * (idx + 1)) % maxn;
            }
            res = (res + dp[i]) % maxn;
        }
        return res;
    }

private:
    int maxn = 1000000007;
};
