class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int minn = 10000;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (sum < minn) minn = sum;
        }
        return max(1 - minn, 1);
    }
};
