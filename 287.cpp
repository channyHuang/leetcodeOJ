class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int pPos = 0, qPos = 0;
        while (1) {
            pPos = nums[pPos];
            pPos = nums[pPos];
            qPos = nums[qPos];

            if (pPos == qPos) break;
        }

        pPos = 0;
        while (nums[pPos] != nums[qPos]) {
            pPos = nums[pPos];
            qPos = nums[qPos];
        }

        return nums[qPos];
    }
};
