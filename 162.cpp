class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        if (len == 2) return nums[0] > nums[1] ? 0 : 1;
        if (len == 3) {
            int idx = 0;
            if (nums[1] > nums[0]) idx = 1;
            if (nums[2] > nums[idx]) idx = 2;
            return idx;
        }
        int stPos = 1, endPos = len - 2;
        while (stPos <= endPos) {
            if (nums[stPos] > nums[stPos - 1] && nums[stPos] > nums[stPos + 1]) return stPos;
            if (nums[endPos] > nums[endPos - 1] && nums[endPos] > nums[endPos + 1]) return endPos;
            stPos++;
            endPos--;
        }
        if (nums[0] > nums[len - 1]) return 0;
        return len - 1;
    }
};