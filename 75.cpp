class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int stPos = 0, endPos = len - 1;
        
        while (stPos < endPos) {
            while (stPos < len - 1 && nums[stPos] == 0) stPos++;      
            while (endPos > 0 && nums[endPos] != 0) endPos--;
            if (stPos < endPos) {
                int tmp = nums[stPos];
                nums[stPos] = nums[endPos];
                nums[endPos] = tmp;
                stPos++;
                endPos--;
            }
        }

        endPos = len - 1;
        while (stPos < endPos) {
            while (stPos < len - 1 && nums[stPos] != 2) stPos++; 
            while (endPos > 0 && nums[endPos] == 2) endPos--;
            if (stPos < endPos) {
                int tmp = nums[stPos];
                nums[stPos] = nums[endPos];
                nums[endPos] = tmp;
                stPos++;
                endPos--;
            }
        }

        return;
    }
};
