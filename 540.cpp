class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        if (len == 1) return nums[0];
        int myxor = nums[0];
        for (int i = 1; i < len; i++) {
            myxor ^= nums[i];
        }
        return myxor;
    }
};
