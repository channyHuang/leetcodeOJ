class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] - nums[i - 1] > res) res = nums[i] - nums[i - 1];
        }
        return res;
    }
};
