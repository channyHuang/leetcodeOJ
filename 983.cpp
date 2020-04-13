class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = min(min(costs[0], costs[1]), costs[2]);
        for (int i = 1; i < len; i++) {
            dp[i] = dp[i - 1] + costs[0];
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (days[i] - days[j] >= 7) break;
            }
            if (j < 0) dp[i] = min(dp[i], costs[1]);
            else dp[i] = min(dp[i], dp[j] + costs[1]);
            for (; j >= 0; j--) {
                if (days[i] - days[j] >= 30) break;
            }
            if (j < 0) dp[i] = min(dp[i], costs[2]);
            else dp[i] = min(dp[i], dp[j] + costs[2]);
        }
        return dp[len - 1];
    }
};
