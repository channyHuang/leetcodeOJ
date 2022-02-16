class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;
        
        sort(nums.begin(), nums.end());
        vector<int> res;
        
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i - 1] == nums[i] - 1) continue;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            if (i < len - 1 && nums[i + 1] == nums[i] + 1) continue;
            if (i < len - 1 && nums[i + 1] == nums[i]) {
                i++;
                continue;
            }
            res.push_back(nums[i]); 
        }
        return res;
    }
};