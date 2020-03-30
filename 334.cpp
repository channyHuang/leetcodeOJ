class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        if (len == 3) return (nums[0] < nums[1] && nums[1] < nums[2]);
        int stPos = 0;
        while (stPos < len - 1 && nums[stPos] >= nums[stPos + 1]) stPos++;
        int midPos = stPos + 1;
        if (midPos >= len) return false;
        int lastPos = midPos + 1;
        while (lastPos < len) {
            if (nums[lastPos] > nums[midPos]) return true;
            if (nums[lastPos] > nums[stPos] && nums[lastPos] < nums[midPos]) midPos = lastPos; 
            else if (nums[lastPos] < nums[stPos] && nums[lastPos - 1] < nums[lastPos]) {
                stPos = lastPos - 1;
                midPos = lastPos;
            }
            lastPos++;
        }
        return false;
    }
};
