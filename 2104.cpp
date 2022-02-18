class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int len = nums.size();
        long long res = 0;
        for (int i = 0; i < len; ++i) {
            int minn = nums[i];
            int maxn = nums[i];
            for (int j = i + 1; j < len; ++j) {
                minn = std::min(minn, nums[j]);
                maxn = std::max(maxn, nums[j]);
                res += (maxn - minn);
            }
        }
        return res;
    }
};
