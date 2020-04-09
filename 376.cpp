class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;
        int up[len], down[len];
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        up[0] = down[0] = 1;
        for (int i = 1; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) up[i] = max(up[i], down[j] + 1);
                else if (nums[i] < nums[j]) down[i] = max(down[i], up[j] + 1);
                else {
                    up[i] = max(up[i], up[j]);
                    down[i] = max(down[i], down[j]);
                }
            }
        }
        return max(up[len - 1], down[len - 1]);
    }
};
