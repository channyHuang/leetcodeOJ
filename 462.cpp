class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        if (len == 2) return abs(nums[0] - nums[1]);
        sort(nums.begin(), nums.end());
        int mid = len / 2;
        int res = 0;
        int target = nums[mid];
        if ((len & 1) == 0) {
            target += nums[mid - 1];
            target /= 2;
        }
        
        for (int i = 0; i < len; i++) {
            res += abs(nums[i] - target);     
        }

        return res;
    }
};
