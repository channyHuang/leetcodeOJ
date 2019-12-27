class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        int reslen = 0;
        if (len < 3) return res;
        for (int i = 0; i < len; i++) {
            int target = 0 - nums[i];
            int stPos = i + 1, endPos = len - 1;
            while (stPos < endPos) {
                if (nums[stPos] + nums[endPos] == target) {
                    int j = 0;
                    for (j = reslen - 1; j >= 0; j--) {
                        if (res[j][0] < nums[i]) {
                            j = -1;
                            break;
                        }
                        if (res[j][0] == nums[i] && res[j][1] == nums[stPos]) break;
                    }
                    if (j < 0) {
                        vector<int> subres;
                        subres.push_back(nums[i]);
                        subres.push_back(nums[stPos]);
                        subres.push_back(nums[endPos]);
                        res.push_back(subres);
                        reslen++;
                    }
                    stPos++;
                    endPos--;
                } else if (nums[stPos] + nums[endPos] > target) {
                    endPos--;
                } else {
                    stPos++;
                }
            }
        }
        return res;
    }
};
