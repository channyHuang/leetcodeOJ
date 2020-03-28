class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len <= 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int sum = nums[i] + nums[j];
                int stPos = j + 1;
                int endPos = len - 1;
                while (stPos < endPos) {
                    if (stPos > j + 1 && nums[stPos] == nums[stPos - 1]) {
                        stPos++;
                        continue;
                    }
                    if (endPos < len - 1 && nums[endPos] == nums[endPos + 1]) {
                        endPos--;
                        continue;
                    }
                    int tmp = nums[stPos] + nums[endPos];
                    if (sum + tmp == target) {
                        vector<int> sub;
                        sub.push_back(nums[i]);
                        sub.push_back(nums[j]);
                        sub.push_back(nums[stPos]);
                        sub.push_back(nums[endPos]);
                        res.push_back(sub);
                        stPos++;
                        endPos--;
                    } else if (sum + tmp < target) stPos++;
                    else endPos--;
                }
            }
        }
        return res;
    }
};
