class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        sort(nums.begin(), nums.end());
        int weight[len];
        memset(weight, 0, sizeof(weight));
        int pos = 1;
        weight[0] = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[pos - 1]) weight[pos - 1] += nums[i];
            else {
                nums[pos++] = nums[i];
                weight[pos - 1] = nums[i];
            }
        }
        if (pos == 1) return weight[0];
        int dp[pos];
        memset(dp, 0, sizeof(dp));
        dp[0] = weight[0];
        dp[1] = (nums[1] - nums[0] == 1 ? max(weight[0], weight[1]) : weight[0] + weight[1]);
        for (int i = 2; i < pos; i++) {
            if (nums[i] - nums[i - 1] == 1) {
                dp[i] = max(dp[i - 2] + weight[i], dp[i - 1]);
            } else dp[i] = dp[i - 1] + weight[i];
        }
        return max(dp[pos - 1], dp[pos - 2]);

    }
};
