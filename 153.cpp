class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        return findMin(nums, 0, len - 1);
    }

    int findMin(vector<int>& nums, int stPos, int endPos) {
        if (stPos == endPos) return nums[stPos];
        if (stPos + 1 == endPos) return min(nums[stPos], nums[endPos]);
        if (nums[stPos] < nums[endPos]) return nums[stPos];
        
        int midPos = (stPos + endPos) / 2;
        if (nums[midPos] > nums[stPos]) return findMin(nums, midPos + 1, endPos);
        else return findMin(nums, stPos, midPos);
    }
};
