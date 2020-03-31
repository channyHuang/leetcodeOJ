class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        if (len <= 1) return (abs(nums[0]) == abs(S) ? 1 : 0);
        int sum[len];
        memset(sum, 0, sizeof(sum));
        sum[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            sum[i] = sum[i + 1] + nums[i];
        }
        count = 0;
        if (sum[0] < S || -sum[0] > S) return count;
        search(nums, sum, S, 1, nums[0]);
        search(nums, sum, S, 1, -nums[0]);
        return count;
    }

    void search(vector<int>& nums, int sum[], int S, int nextPos, int lastSum) {
        if (nextPos >= nums.size()) {
            if (lastSum == S) count++;
            return;
        }
        if (lastSum + sum[nextPos] < S || lastSum - sum[nextPos] > S) return;
        search(nums, sum, S, nextPos + 1, lastSum + nums[nextPos]);
        search(nums, sum, S, nextPos + 1, lastSum - nums[nextPos]);
    }

private:
    int count;
};
