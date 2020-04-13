class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 0 || k <= 1) return 0;
        long long sum = 1;
        int stPos = 0;
        int res = 0;
        for (int j = 0; j < len; j++) {
            sum *= nums[j];           
            while (sum >= k) {
                sum /= nums[stPos];
                stPos++;
            }
            res += (j - stPos + 1); 
        }
        return res;
    }
};
