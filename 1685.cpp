class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int len = nums.size();
        vector<int> diff(len, 0);
        vector<int> res(len, 0);
        for (int i = 1; i < len; i++) {
            diff[i - 1] = abs(nums[i] - nums[i - 1]);
            res[0] += (len - i) * diff[i - 1];
        }
        for (int i = 1; i < len; i++) {
            res[i] = res[i - 1] - (len - i) * diff[i - 1] + i * diff[i - 1];
        }
        return res;
    }
};
