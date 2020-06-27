class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        if (len <= 1) return res;
        vector<int> sortnums;
        sortnums.push_back(nums[len - 1]);
        for (int i = len - 2; i >= 0; i--) {
            int idx = mysort(sortnums, nums[i]);
            res[i] = idx + 1;
            sortnums.insert(sortnums.begin() + idx + 1, nums[i]);
        }
        return res;
    }

    int mysort(vector<int>& sortnums, int target) {
        int stPos = 0, endPos = sortnums.size() - 1;
        int idx = -1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (sortnums[midPos] >= target) endPos = midPos - 1;
            else {
                idx = midPos;
                stPos = midPos + 1;
            }
        }
        return idx;
    }
};