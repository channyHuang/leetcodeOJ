class Solution {
public:
    class Node {
    public:
        int base;
        int index;
        Node (int _b = 0, int _i = 0) {
            base = _b;
            index = _i;
        }
    };

    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        int maxn = 2147483647;
        if (len <= 0) return 0;
        if (target <= 0) return 0;
        sort(nums.begin(), nums.end());
        long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            if (nums[i] > target) continue;
            dp[nums[i]] = 1;
        }
        for (int i = nums[0] + 1; i <= target; i++) {
            for (int j = 0; j < len; j++) {
                if (i - nums[j] <= 0) continue;
                if (maxn - dp[i - nums[j]] < dp[i]) dp[i] = maxn;
                else dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
