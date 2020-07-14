class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sets.insert((long long)nums[i]);
        }
        maxLen = 0;
        for (int i = 0; i < len; i++) {
            if (sets.find((long long)nums[i] - 1) != sets.end()) continue;
            long long j;
            for (j = (long long)nums[i] + 1; j <= (long long)nums[i] + len; j++) {
                if (sets.find(j) == sets.end()) break;
            }
            maxLen = max(maxLen, j - nums[i]);
            if (maxLen >= len) break;
        }
        return maxLen;
    }
private:
    unordered_set<long long> sets;
    long long maxLen;
};
