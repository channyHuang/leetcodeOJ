class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return true;
        int maxn[len][len] = {0};
    
        for (int i = 0; i < len - 1; i++) {
            maxn[i][i] = nums[i];
            maxn[i][i + 1] = abs(nums[i] - nums[i + 1]);
        }
        for (int d = 2; d < len; d++) {
            for (int i = 0; i < len; i++) {
                if (i + d >= len) break;
                maxn[i][i + d] = max(nums[i] - maxn[i + 1][i + d], nums[i + d] - maxn[i][i + d - 1]);
            }
        }
        return maxn[0][len - 1] >= 0 ? true : false;
    }
};
