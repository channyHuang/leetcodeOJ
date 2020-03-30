class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return;
        if (len == 2) {
            int tmp = nums[0];
            nums[0] = nums[1];
            nums[1] = tmp;
            return;
        }
        int i = len - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) i--;
        if (i == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        sort(nums.begin() + i, nums.end());
        int idx = i;
        while (idx < len && nums[idx] <= nums[i - 1]) idx++;
        for (int j = idx + 1; j < len; j++) {
            if (nums[j] > nums[i - 1] && nums[j] < nums[idx]) idx = j;
        }
        int tmp = nums[i - 1];
        nums[i - 1] = nums[idx];
        nums[idx] = tmp;
        
    }
};
