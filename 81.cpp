class Solution {
public:
    int search(vector<int>& nums, int target) {
        int stPos = 0, endPos = nums.size() - 1;
        return search(nums, target, stPos, endPos);
    }

    int search(vector<int>& nums, int target, int stPos, int endPos) {
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (target == nums[midPos]) return true;
            if (nums[stPos] < nums[endPos]) {
                if (nums[midPos] > target) endPos = midPos - 1;
                else stPos = midPos + 1;
            } else {
                int tmp = search(nums, target, midPos + 1, endPos);
                if (tmp) return tmp;
                tmp = search(nums, target, stPos, midPos - 1);
                return tmp;
            }
        }
        return false;
    }
};