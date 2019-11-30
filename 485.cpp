class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i]) count++;
            else {
                if (res < count) res = count;
                count = 0;
            }
        }
        if (res < count) res = count;
        return res;
    }
};
