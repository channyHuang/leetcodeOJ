class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return false;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if ((sum & 1) == 1) return false;
        sum /= 2;
        bool dp[len][sum + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            if (nums[i] > sum) continue;
            dp[i][nums[i]] = true;
            for (int j = nums[i] + 1; j <= sum; j++) {
                for (int k = 0; k < i; k++) {
                    if (dp[k][j - nums[i]]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }  
        }
        return dp[len - 1][sum];
    }
};
