class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int len = nums.size();
        int minn = INT_MAX;
        for (int i = 0; i < len; i++) {
            if (nums[i] != target) continue;
            if (abs(i - start) < minn) {
                minn = abs(i - start);
            }
        }
        return minn;
    }
};
