class Solution {
public:
    int minMoves(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        if (len == 2) return abs(nums[0] - nums[1]);
        sort(nums.begin(), nums.end());
        int res = 0;
    
        for (int i = 1; i < len; i++) {
            res += (nums[i] - nums[0]);
        }
        return res;
    }
};
