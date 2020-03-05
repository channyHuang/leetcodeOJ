class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        int len = nums.size();
        if (len <= 0) return res;
        int vec[len] = {0};
        bool used[len] = {0};
        search(vec, nums, len, used, 0);
        return res;
    }

    void search(int vec[], vector<int>& nums, int len, bool used[], int pos) {
        if (pos == len) {
            vector<int> subres;
            for (int i = 0; i < len; i++) {
                subres.push_back(vec[i]);
            }
            res.push_back(subres);
            return;
        }

        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            vec[pos] = nums[i];
            used[i] = true;
            search(vec, nums, len, used, pos + 1);
            used[i] = false;
        }
    }
};
