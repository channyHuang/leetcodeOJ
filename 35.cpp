class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int stPos = 0, endPos = nums.size() - 1;
        return find(nums, stPos, endPos, target);
    }

    int find(vector<int>& nums, int stPos, int endPos, int target) {
        if (stPos > endPos) return endPos + 1;
        int midPos = (stPos + endPos) / 2;
        if (nums[midPos] == target) return midPos;
        if (nums[midPos] > target) return find(nums, stPos, midPos - 1, target);
        else return find(nums, midPos + 1, endPos, target);
    }
};
