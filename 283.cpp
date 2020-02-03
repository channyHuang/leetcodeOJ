class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int res = 0;
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                continue;
            }
            nums[res++] = nums[i];
        }
        for (int i = 0; i < zeroCount; i++) {
            nums[nums.size() - 1 - i] = 0;
        }
    }
};