class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        vector<int> res;
        int tmpSum = 0;
        for (int i = 0; i < len; i++) {
            tmpSum += nums[i];
            res.push_back(nums[i]);
            if (tmpSum > sum - tmpSum) break;
        }
        return res;
    }
};
