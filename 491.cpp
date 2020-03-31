class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int len = nums.size();

        set<int> sets;
        for (int i = 0; i < len - 1; i++) {
            if (sets.find(nums[i]) != sets.end()) continue;
            sets.insert(nums[i]);
            vector<int> subres;
            subres.resize(len);
            subres[0] = nums[i];
            search(nums, subres, i, 1);
        }
        return res;
    }

    void search(vector<int>& nums, vector<int>& vec, int lastIdx, int vecLen) {
        set<int> sets;
        for (int i = lastIdx + 1; i < nums.size(); i++) {
            if (sets.find(nums[i]) != sets.end()) continue;
            sets.insert(nums[i]);
            if (nums[i] >= nums[lastIdx]) {
                vec[vecLen] = nums[i];
                vector<int> subres;
                for (int i = 0; i <= vecLen; i++) {
                    subres.push_back(vec[i]);
                }
                res.push_back(subres);
                search(nums, vec, i, vecLen + 1);
            }
        }
    }

private:
    vector<vector<int>> res;
};
