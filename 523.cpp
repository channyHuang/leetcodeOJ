class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int sum[len] = {0};
        sum[0] = nums[0];
        if (k == 0) {
            for (int i = 1; i < len; i++) {
                if (nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i - 1] + nums[i];
            if (sum[i] % k == 0) return true;
        }
        for (int i = 1; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((sum[j] - sum[i - 1]) % k == 0) return true; 
            }
        }
        return false;
    }
};
