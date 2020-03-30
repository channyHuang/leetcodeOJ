class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();       
        {
            vector<int> subres;
            res.push_back(subres);
        }       
        if (len <= 0) return res;
        if (len == 1) {
            vector<int> subres;
            subres.push_back(nums[0]);
            res.push_back(subres);
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            vector<int> subres;
            subres.push_back(nums[i]);
            res.push_back(subres);
            search(nums, subres, i);
        }
        return res;
    }

    void search(vector<int>& nums, vector<int>& vec, int pos) {
        for (int i = pos + 1; i < nums.size(); i++) {
            if (i > pos + 1 && nums[i] == nums[i - 1]) continue;
            vector<int> sub = vec;
            sub.push_back(nums[i]);
            res.push_back(sub);
            search(nums, sub, i);
        }
    }

private:
    vector<vector<int>> res;
};
