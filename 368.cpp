class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> finres;
        finres.push_back(nums[0]);
        vector<int> res[len];
        int maxLen = 1;
        int dp[len];
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            res[i].push_back(nums[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] != 0) continue;
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    res[i] = res[j];
                    res[i].push_back(nums[i]);
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                finres = res[i];
            }
        }
        return finres;
    }
};
