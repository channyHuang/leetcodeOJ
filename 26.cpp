class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int res = 1;
        int pre = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pre) continue;
            else {
                nums[res++] = nums[i];
                pre = nums[i];
            }
        }
        return res;
    }
};
