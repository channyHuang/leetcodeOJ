class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        int sum = 0;
        int res = len + 5;
        int left = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            while (sum >= s) {
                res = min(i - left + 1, res);
                sum -= nums[left];
                left++;
            }
        }
        if (res > len) return 0;
        return res;
    }
};
