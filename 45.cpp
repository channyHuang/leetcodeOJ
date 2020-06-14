class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        res[0] = 0;
        int pos = 0;
        for (int i = 1; i < len; i++) {
            if (nums[pos] + pos >= i) res[i] = res[pos] + 1;
            else {
                pos++;
                i--;
            }
        }
        return res[len - 1];
    }
};
