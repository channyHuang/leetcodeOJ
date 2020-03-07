class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //1 ≤ a[i] ≤ n 
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(idx + 1);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};
