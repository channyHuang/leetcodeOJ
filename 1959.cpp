class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1 || k == len - 1) return 0;
        int res = 0;
        vector<int> sum(len + 1, 0);
        int maxnum = nums[0];
        vector<vector<int>> maxn(len, vector<int>(len, 0));
        for (int i = 1; i <= len; ++i) {
          sum[i] = nums[i - 1] + sum[i - 1];
          maxnum = std::max(maxnum, nums[i - 1]);
          maxn[i - 1][i - 1] = nums[i - 1];
        }
        // 0 <= k <= nums.length - 1
        if (k == 0) {
          return maxnum * len - sum[len];
        }
        vector<vector<int>> waste(len, vector<int>(len, 0));
        vector<vector<int>> dp(len, vector<int>(k + 2, 1000000009));
        
        for (int l = 1; l < len; ++l) {
          for (int i = 0; i < len; ++i) {
            if (i + l >= len) break;
            maxn[i][i + l] = std::max(maxn[i][i + l - 1], nums[i + l]);
            waste[i][i + l] = (maxn[i][i + l] * (l + 1)) - sum[i + l + 1] + sum[i];
          }
        }
        for (int i = 0; i < len; ++i) {
          dp[i][1] = maxn[0][i] * (i + 1) - sum[i + 1];
        }
        for (int l = 2; l <= k + 1; ++l) {
          for (int i = l - 1; i < len; ++i) {
            if (i == l - 1) dp[i][l] = 0;
            for (int x = l - 2; x < i; ++x) {
              dp[i][l] = std::min(dp[i][l], dp[x][l - 1] + waste[x + 1][i]);
            }
          }
        }

        return dp[len - 1][k + 1];
    }
};

