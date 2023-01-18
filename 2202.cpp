class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return ((k & 1) ? -1 : nums[0]);
        if (k <= 0) return nums[0];
        if (k == 1) return nums[1];
        // k > 1, len > 1
        int res = -1, i = 0;
        for (i = 0; i < len; ++i) {
            if (k <= 1) break;
            k--;          
            if (res < nums[i]) res = nums[i];
        }
        // k >= 1
        if (i == len) {
            return res;
        }
        // k == 1, i < len
        if (i == len - 1) return res;
        // i < len - 1
        return std::max(res, nums[i + 1]);
    }
};
