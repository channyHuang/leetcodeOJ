class Solution {
public:
    bool flag = false;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        flag = false;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int total = 0, sum = 0;
        for (int i = 0; i < len; i++) total += nums[i];
        if (total % k) return false;
        sum = total / k;
        if (nums[len - 1] > sum) return false;
        vector<bool> used;
        used.resize(len);
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] == sum) used[i] = true;
            else break;
        }
        
        int pos = len - 1;
        while (pos >= 0 && used[pos]) pos--;
        if (pos < 0) return true;
        used[pos] = true;
        int curSum = nums[pos];
        searchUsed(nums, used, sum, curSum);

        return flag;
    }

    void searchUsed(vector<int>& nums, vector<bool>& used, int sum, int curSum) {
        if (curSum == sum) {
            int i = 0;
            for (i = nums.size() - 1; i >= 0; i--) {
                if (used[i]) continue;
                else break;
            }
            if (i < 0) {
                flag = true;
                return;
            }
            searchUsed(nums, used, sum, 0);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (flag) return;
            if (used[i] || curSum + nums[i] > sum) continue;
            used[i] = true;
            searchUsed(nums, used, sum, curSum + nums[i]);
            used[i] = false;
        }
    }
};
