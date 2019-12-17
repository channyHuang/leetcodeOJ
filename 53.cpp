class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int dp[len] = {0};
        int res = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (res < dp[i]) res = dp[i];
        }
        return res;
    }
};
