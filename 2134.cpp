class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int len = nums.size();
        if (len <= 3) return 0;
        vector<int> count(len, 0);
        if (nums[0] == 1) count[0] = 1;
        for (int i = 1; i < len; ++i) {
            count[i] = count[i - 1];
            if (nums[i] == 1) count[i]++;
        }
        int total = count[len - 1];
        if (total >= len - 1 || total <= 1) return 0;
        int res = total - count[total - 1];
        for (int i = 1; i < len; ++i) {
            if (i + total <= len) {
                res = std::min(res, total - (count[i + total - 1] - count[i - 1]));
            } else {
                res = std::min(res, total - (count[len - 1] - count[i - 1] + count[i + total - len - 1]));
            }
        } 
        return res;
    }
};

