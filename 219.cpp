class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> uninums;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (uninums.find(nums[i]) != uninums.end()) {
                for (int j = i - 1; j >= 0; j--) {
                    if (i - j > k) break; 
                    if (nums[i] == nums[j]) return true;
                }
            }
            uninums.insert(nums[i]);
        }
        return false;
    }
};
