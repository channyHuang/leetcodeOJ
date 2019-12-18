class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len <= 1) return 0;
        int sum[len] = {0};
        sum[0] = nums[0];
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        if (sum[len - 1] - sum[0] == 0) return 0;
        for (int i = 1; i < len; i++) {
            if (sum[len - 1] - sum[i] == sum [i - 1]) return i;
        }
        return -1;
    }
};
