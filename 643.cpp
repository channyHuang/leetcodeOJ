class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < k) return 0;
        long long cursum = 0;
        for (int i = 0; i < k; i++) cursum += nums[i];
        double res = 0;  
        long long orisum = cursum;
        for (int i = k; i < len; i++) {
            cursum = cursum - nums[i - k] + nums[i];
            if (cursum <= orisum) continue;
            orisum = cursum;
        }
        res = orisum * 1.0 / k;
        return res;
    }   
};