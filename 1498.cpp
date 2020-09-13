class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 1) return (nums[0] * 2 <= target ? 1 : 0);
        sort(nums.begin(), nums.end());
        if (target >= nums[len - 1] * 2) return (power(len) - 1 + maxn) % maxn;
        if (target < nums[0] * 2) return 0;
        long long res = 0;
        int stPos = 0;
        for (; stPos < len; stPos++) {
            if (nums[stPos] * 2 > target) break;
            int endPos = findMaxRight(nums, stPos, target - nums[stPos]);
            res += power(endPos - stPos);
            res %= maxn;
        }
        return res;
    }
    //nums[res] <= target
    int findMaxRight(vector<int>& nums, int stPos, int target) {
        int endPos = nums.size() - 1;
        int res = stPos;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (nums[midPos] <= target) {
                res = midPos;
                stPos = midPos + 1;
            } else {
                endPos = midPos - 1;
            }
        }
        return res;
    }
    //2^n % maxn
    int power(int n) {
        if (n == 0) return 1;
        if (n <= 10) return (1 << n);
        int i = 1;
        long long cur = 2;
        long long res = 1;
        while (n) {
            if (i > n) {
                i = 1;
                cur = 2;
            }
            n -= i;
            res *= cur;
            res %= maxn;

            i <<= 1;
            cur *= cur;
            cur %= maxn;
        }
        return res;
    }

private:
    int maxn = 1000000007;
};
