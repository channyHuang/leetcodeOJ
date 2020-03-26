class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len = nums.size();
        vector<int> res;
        if (len <= 0) return res;
        res.push_back(nums[0]);
        if (len == 1) {          
            return res;
        }
        for (int i = 1; i < len; i++) {
            res.push_back(nums[i]);
            if (index[i] == i) continue;
            int count = index[i];
            for (int j = i; j > count; j--) {
                res[j] = res[j - 1];
            }
            res[count] = nums[i];
        }
        
        return res;
    }

};
