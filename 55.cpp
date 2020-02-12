class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return true;
        int curPos = 0;
        int maxPos = 0;
        while (maxPos < len - 1) {
            if (curPos > maxPos) return false;
            if (nums[curPos] + curPos > maxPos) maxPos = nums[curPos] + curPos;
            curPos++;
        }
        return true;
    }
};