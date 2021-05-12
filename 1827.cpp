class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1]) continue;
            res += (nums[i - 1] + 1 - nums[i]);
            nums[i] = nums[i - 1] + 1;
        }
        return res;
    }
};
