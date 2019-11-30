class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        if (len == 1) return 1;
        if (len == 2) return (nums[0] < nums[1] ? 2 : 1);

        int large[len] = {0};
        large[0] = 1;
        int res = 1;
        for (int i = 1; i < len; i++) {
            large[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) large[i] = max(large[i], large[j] + 1);
            }
            if (large[i] > res) res = large[i];
        }
        return res;
    }
};
