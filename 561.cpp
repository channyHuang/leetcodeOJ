class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; i += 2) {
            res += nums[i];
        }
        return res;
    }
};
