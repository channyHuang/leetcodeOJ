class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size();
        //greedy
        long long target = 1;
        long long curSum = 0;
        int pos = 0;
        int res = 0;
        while (target <= n) {
            if (pos >= len) {
                res++;
                curSum += target;
                target = curSum + 1;
            } else if (nums[pos] < target) {
                curSum += nums[pos];
                if (target <= curSum) target = curSum + 1;
                pos++;
            } else if (nums[pos] == target) {
                curSum += nums[pos];
                target = curSum + 1;
                pos++;
            } else {
                res++;
                curSum += target;
                target = curSum + 1;
            }
        }
        return res;
    }
};
