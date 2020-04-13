class Solution {
public:
    int minSteps(int n) {
        int dp[1001];
        memset(dp, 0, sizeof(dp));
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            dp[i] = i;
            int stPos = 2;
            int endPos = i / 2;
            while (stPos <= endPos) {
                if (i % stPos != 0) {
                    stPos++;
                    endPos = i / stPos;
                    continue;
                }
                dp[i] = min(dp[i], dp[stPos] + i / stPos);
                dp[i] = min(dp[i], dp[i / stPos] + stPos);
                stPos++;
                endPos = i / stPos;
            }
        }
        return dp[n];
    }
};
