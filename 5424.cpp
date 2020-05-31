class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int maxn = max(nums[0], nums[1]);
        int second = min(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            if (nums[i] >= maxn) {
                second = maxn;
                maxn = nums[i];
            } else if (nums[i] > second) {
                second = nums[i];
            }
        }
        return (maxn - 1) * (second - 1);
    }
};
