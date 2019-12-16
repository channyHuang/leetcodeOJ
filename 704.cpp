class Solution {
public:
    int search(vector<int>& nums, int target) {
        int stPos = 0, endPos = nums.size() - 1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (target == nums[midPos]) return midPos;
            if (target > nums[midPos]) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return -1;
    }
};
