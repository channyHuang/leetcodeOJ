class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        int reslen = 0;
        if (len < 3) return res;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                bool flag = false;
                for (int k = reslen - 1; k >= 0; k--) {
                    if (nums[i] == res[k][0] && nums[j] == res[k][1]) {
                        flag = true;
                        break;
                    }
                    if (nums[i] > res[k][0] && nums[j] > res[k][1]) break;
                }
                if (flag) continue;

                int target = 0 - nums[i] - nums[j];
                if (target < nums[j]) continue;
                int idx = find(nums, target, j + 1);
                if (idx != -1) {
                    vector<int> subres;
                    subres.push_back(nums[i]);
                    subres.push_back(nums[j]);
                    subres.push_back(target);
                    res.push_back(subres);
                    reslen++;
                }
            }
        }
        return res;
    }

    int find(vector<int>& nums, int target, int stPos) {
        int endPos = nums.size() - 1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (nums[midPos] == target) return midPos;
            if (nums[midPos] < target) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return -1;
    }
};
