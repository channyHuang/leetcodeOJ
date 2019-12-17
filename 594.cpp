class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int len = nums.size();
        if (len <= 1) return 0;
        if (nums[len - 1] == nums[0]) return 0;
        int count[2] = {0};
        count[0] = 1;
        int pos = 1;
        int idx = 0;
        while (pos < len) {
            if (nums[pos] == nums[idx]) count[0]++;
            else {
                if (nums[pos] - nums[idx] == 1) count[1]++;
                else {
                    if (count[1] == 0) {
                        idx = pos;
                        count[0] = 1;
                    } else {
                        if (res < count[0] + count[1]) res = count[0] + count[1];
                        idx += count[0];
                        count[0] = count[1];
                        count[1] = 0;
                        pos--;
                    }
                }
            }
            pos++;
        }
        if (count[1] != 0 && res < count[0] + count[1]) res = count[0] + count[1];

        return res;
    }
};
