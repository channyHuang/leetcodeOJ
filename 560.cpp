class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 0) return 0;
        int sum[len];
        memset(sum, 0, sizeof(sum));
        sum[0] = nums[0];
        int res = 0;
        if (sum[0] == k) res++;
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i - 1] + nums[i];
            if (sum[i] == k) res++;
            for (int j = 0; j < i; j++) {
                if (sum[i] - sum[j] == k) res++;
            }
        }
        return res;
    }
};
