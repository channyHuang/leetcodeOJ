class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return (nums[0] % 3 == 0 ? nums[0] : 0);
        }
        int dp[3] = {0, 0, 0};
        for (int i = 0; i < len; i++) {
            int left = nums[i] % 3;
            int m[3];
            for (int j = 0; j < 3; j++) 
                m[j] = dp[(3 + j - left) % 3];

            for (int j = 0; j < 3; j++) 
                if (m[j] || left == j) dp[j] = max(dp[j], m[j] + nums[i]);
        }
        return dp[0];
    }
};
