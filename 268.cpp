class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        long long sum = (n - 1) * n;
        sum >>= 1;

        for (int i = 0; i < n - 1; i++) {
            sum -= nums[i];
        }

        return (int)sum;
    }
};
