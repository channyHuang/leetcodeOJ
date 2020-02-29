class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if (len <= 0) return res;
        if (len == 1) {
            res.push_back(0);
            return res;
        }
        int left[len] = {nums[0]};
        int right[len];
        right[len - 1] = nums[len - 1];
        for (int i = 1; i < len; i++) {
            left[i] = left[i - 1] * nums[i];
            right[len - i - 1] = right[len - i] * nums[len - i - 1];
        }
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                res.push_back(right[1]);
            } else if (i == len - 1) {
                res.push_back(left[len - 2]);
            } else
                res.push_back(left[i - 1] * right[i + 1]);
        }
        return res;
    }
};
