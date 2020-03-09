class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        res.resize(len);
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] < nums[j]) res[j]++;
                else if (nums[i] > nums[j]) res[i]++;
            }
        }
        return res;
    }
};
