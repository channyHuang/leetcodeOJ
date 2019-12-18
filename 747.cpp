class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1) return 0;

        int res = nums[0] > nums[1] ? 0 : 1;
        int maxn = nums[res];
        int secmax = nums[1 - res];
        for (int i = 2; i < len; i++) {
            if (nums[i] > maxn) {
                secmax = maxn;
                maxn = nums[i];
                res = i;
            } else if (nums[i] > secmax) {
                secmax = nums[i];
            }
        }
        if (maxn >= (secmax << 1) ) return res;
        return -1;
    }
};
