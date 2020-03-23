class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return nums;
        int xorres = 0;
        for (int i = 0; i < len; i++) {
            xorres ^= nums[i];
        }
        int last1 = xorres & (-xorres);
        int x = 0;
        for (int i = 0; i < len; i++) {
            if (last1 & nums[i]) x ^= nums[i];
        }
        vector<int> res;
        res.push_back(x);
        res.push_back(xorres ^ x);
        return res;
    }
};
