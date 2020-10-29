class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        len = nums.size();
        res = INT_MAX;
        presum = vector<int>(len, 0);
        presum[0] = nums[0];
        for (int i = 1; i < len; i++) {
            presum[i] = presum[i - 1] + nums[i];
        }
        if (m == 1) return presum[len - 1];
        if (m == len) return *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(m + 1, vector<int>(len, INT_MAX));
        dp[1][0] = nums[0];
        for (int j = 1; j < len; j++) {
            dp[1][j] = dp[1][j - 1] + nums[j];
        }
        for (int i = 2; i <= m; i++) {
            for (int j = i - 1; j < len; j++) {
                for (int k = i - 2; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], presum[j] - presum[k]));
                }
            }
        }

        return dp[m][len - 1];
    }
    //lastEnd >= 0
    void splitArray(vector<int>& nums, int m, int lastEnd, int curRes) {
        if (len - lastEnd - 1 < m || m <= 0) return;
        if (m == 1) {
            int lastRes = max(curRes, presum[len - 1] - presum[lastEnd]);
            res = min(res, lastRes);
            return;
        }
        if (m == len - lastEnd - 1) {
            int lastRes = max(curRes, *max_element(nums.begin() + lastEnd + 1, nums.end()));
            res = min(res, lastRes);
            return;
        }
        int partsum = 0;
        for (int i = lastEnd + 1; i < len; i++) {
            partsum += nums[i];
            int nextRes = max(partsum, curRes);
            splitArray(nums, m - 1, i, nextRes);
        }
    }


private:
    int len;
    int res;
    vector<int> presum;
};
