class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;
        int dp[len];
        int count[len];
        memset(dp, 0, sizeof(dp));
        memset(count, 0, sizeof(count));
        int maxnlen = 1;
        dp[0] = 1;
        count[0] = 1;
        for (int i = 1; i < len; i++) {
            dp[i] = 1;
            count[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] >= nums[i]) continue;
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
                maxnlen = max(maxnlen, dp[i]);
            }
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (dp[i] == maxnlen) sum += count[i];
        }
        return sum;
    }
};
