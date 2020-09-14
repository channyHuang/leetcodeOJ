class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return -1;
        sort(nums.begin(), nums.end());
        int minn = nums[1] - nums[0], maxn = nums[len - 1] - nums[0];
        for (int i = 1; i < len; i++) {
            minn = min(minn, nums[i] - nums[i - 1]);
        }
        while (minn <= maxn) {
            //cout << minn << " " << maxn << endl;
            int midn = (minn + maxn) / 2;
            int stPos = 0, endPos;
            int count = 0;
            for (stPos = 0; stPos < len - 1; stPos++) {
                int st = stPos, end = len - 1;
                int endPos = stPos;
                while (st <= end) {
                    int mid = (st + end) / 2;
                    if (nums[mid] - nums[stPos] <= midn) {
                        endPos = mid;
                        st = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                count += (endPos - stPos);
            }
            //cout << count << endl;
            if (count == k) {
                maxn = midn;
            } else if (count > k) {
                maxn = midn;
            } else {
                minn = midn + 1;
            }
            if (maxn == minn) break;
        }
        return maxn;
    }
};
