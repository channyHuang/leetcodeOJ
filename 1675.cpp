class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        len = nums.size();
        int maxOdd = 0;
        int maxIdx = 0;
        int minn = INT_MAX;
        priority_queue<int> qu;
        int maxn = 0;
        for (int i = 0; i < len; i++) {
            int odd = (nums[i] >> (__builtin_ctz(nums[i])));
            if (odd > maxOdd) {
                maxOdd = odd;
                maxIdx = i;
            }
            if (nums[i] & 1) {
                nums[i] <<= 1;
            }
            minn = min(minn, nums[i]);
            maxn = max(maxn, nums[i]);
            qu.push(nums[i]);
        }
        int res = maxn - minn;       
        while (!qu.empty()) {
            int cur = qu.top();
            res = min(res, cur - minn);
            if (cur <= maxOdd || (cur & 1) || (cur >> 1) < minn) break;
            qu.pop();
            while (((cur & 1) == 0) && ((cur >> 1) >= minn)) {
                cur >>= 1;
            }
            qu.push(cur);
        }

        while (!qu.empty()) {
            int cur = qu.top();
            qu.pop();
            res = min(res, cur - minn);
            if (cur <= maxOdd || (cur & 1)) break;
            cur >>= 1;
            minn = min(cur, minn);
            qu.push(cur);
        }

        return res;
    }

private:
    int len;
};
