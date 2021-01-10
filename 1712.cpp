class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int len = nums.size();
        vector<int> sums(len, 0);
        sums[0] = nums[0];
        for (int i = 1; i < len; i++) {
            sums[i] = sums[i - 1] + nums[i];
        }
        //cout << "------" << endl;
        long long res = 0;
        for (int i = 0; i < len - 2; i++) {
            int leftsum = sums[i];
            int midtarget = leftsum * 2;
            vector<int>::iterator itr = lower_bound(sums.begin() + i + 1, sums.end(), midtarget);
            int mpos = distance(sums.begin(), itr);
            //cout << mpos << " " << endl;
            if (mpos >= len) {
                break;
            }
            int target = (sums[len - 1] - sums[i]) / 2 + leftsum;
            vector<int>::iterator nitr = upper_bound(sums.begin() + mpos, sums.end(), target);
            int rpos = distance(sums.begin(), nitr);
            //cout << rpos << " " << endl;
            if (rpos >= len) {
                rpos = len - 1;
            }
            //cout << len << " " << i << " " << mpos << " " << rpos << endl;
            if (rpos > mpos) {
                //if (i < 10 || i > 99990) cout << (rpos - mpos) << endl;
                res += (rpos - mpos);
                res %= maxn;
            }
        }

        return res;
    }

private:
    int maxn = 1000000007;
};
