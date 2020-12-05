class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        if (len <= 1) return len;
        if (len == 2) {
            if (nums[0] == 0) res++;
            if (nums[1] == 0) res++;
            return res;
        }
        if (len == 3) {
            for (int i = 0; i < len; i++) {
                if (nums[(i + 1) % 3] == nums[(i + 2) % 3]) res++;
            }
            return res;
        }
        //len >= 4, sum[i] = nums[i] + nums[i + 2] + ...
        vector<int> sum(len + 2, 0);
        for (int i = len - 1; i >= 0; i--) {
            sum[i] = nums[i] + sum[i + 2];
        }
        //del nums[0]
        if (sum[1] == sum[2]) res++;
        //del nums[1] 
        if (nums[0] + sum[3] == sum[2]) res++;
        //del nums[i]
        for (int i = 2; i < len; i++) {
            //i is odd
            if (i & 1) {
                if (sum[0] - sum[i + 1] + sum[i + 2] == sum[1] - sum[i] + sum[i + 1]) res++;
            } else {
                if (sum[0] - sum[i] + sum[i + 1] == sum[1] - sum[i + 1] + sum[i + 2]) res++;
            }
        }
        
        return res;
    }
};
