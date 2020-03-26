class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return res;
        bool used[len];
        vector<int> sub = nums;
        memset(used, 0, sizeof(used));
        sort(nums.begin(), nums.end());
        search(nums, used, sub, 0);
        return res;
    }

    void search(vector<int>& nums, bool used[], vector<int>& sub, int pos) {
        if (pos >= nums.size()) {
            vector<int> subres;
            for (int i = 0; i < pos; i++) {
                subres.push_back(sub[i]);
            }
            res.push_back(subres);
            return;
        }
        bool hasPre = false;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (hasPre && nums[i] == pre) continue;
            hasPre = true;
            pre = nums[i];
            sub[pos] = nums[i];
            used[i] = true;
            search(nums, used, sub, pos + 1);
            used[i] = false;
        }
    }

private:
    vector<vector<int>> res;
};
