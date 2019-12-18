class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int pos = 0, count = 1, res = 1;
        if (nums.size() <= 1) return nums.size();
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) count++;
            else {
                if (res < count) res = count;
                pos = i;
                count = 1;
            }
        }
        if (res < count) res = count;
        return res;
    }
};
