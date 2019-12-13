class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        bool changed = false;
        int pos = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] >= nums[i - 1]) continue;
            if (changed) return false;
            if (i == len - 1) return true;
            changed = true;
            if (i == 1) {
                nums[i - 1] = nums[i];
                continue;
            }
            //i-1 >= i-2
            if (nums[i - 1] == nums[i - 2]) {
                nums[i] = nums[i - 1];
                continue;
            }
            //i-1 > i-2
            if (nums[i] <= nums[i - 2]) {
                nums[i] = nums[i - 1];
                continue;
            }
            nums[i - 1] = nums[i];
        }
        return true;
    }
};
