class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len = nums.size();
        if (len <= 1) return 1;
        int stPos = 0;
        int res = 1;
        int maxn = nums[0];
        int minn = nums[0];
        for (int i = 1; i < len; i++) {
            maxn = max(maxn, nums[i]);
            minn = min(minn, nums[i]);
            if (maxn - minn <= limit) {
                res = max(res, i - stPos + 1);
                continue;
            }
            while (maxn - minn > limit) {
                if (maxn == nums[stPos]) {
                    maxn = nums[stPos + 1];
                    for (int j = stPos + 2; j <= i; j++) maxn = max(maxn, nums[j]);
                }
                if (minn == nums[stPos]) {
                    minn = nums[stPos + 1];
                    for (int j = stPos + 2; j <= i; j++) minn = min(minn, nums[j]);
                }
                stPos++;
            }
        }
        return res;
    }
};
