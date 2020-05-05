class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        if (len <= 2) return count;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int k;
                for ( k = j + 1; k < len; k++) {
                    if (nums[i] + nums[j] > nums[k]) count++;
                    else break;
                }
            }
        }
        return count;
    }
};
