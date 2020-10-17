class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        res = 0;
        search(nums, 0, len - 1);
        return res;
    }

    void search(vector<int>& nums, int stPos, int endPos) {
        if (stPos >= endPos) return;
        int midPos = (stPos + endPos) / 2;
        search(nums, stPos, midPos);
        search(nums, midPos + 1, endPos);
        int i = stPos;
        for (int j = midPos + 1; j <= endPos; j++) {
            while (i <= midPos && nums[i] <= 2 * (long long)nums[j]) i++;
            res += (midPos - i + 1);
        }
        inplace_merge(nums.begin() + stPos, nums.begin() + midPos + 1, nums.begin() + endPos + 1);
    }

private:
    int res;
};
