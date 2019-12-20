class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + k == nums[j]) {
                    res++;
                    break;
                }
                if (nums[i] + k < nums[j]) break;
            }
        }
        return res;
    }
};
