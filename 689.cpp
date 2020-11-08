class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res(3, 0);
        vector<int> presum(len, 0); //nums[i - k + 1~i]长度为k的子数组的和
        vector<int> sum1(len, 0); //nums[0~i]中长度为k的子数组中最大的子数组最后一个数的下标
        vector<pair<int, int>> sum2(len, pair<int, int>(k - 1, k * 2 - 1)); //end pos
        for (int i = 0; i < k; i++) {
            presum[k - 1] += nums[i];
        }
        sum1[k - 1] = k - 1;
        int maxn = 0;
        for (int i = k; i < len; i++) {
            presum[i] = presum[i - 1] - nums[i - k] + nums[i];
            if (presum[sum1[i - 1]] >= presum[i]) {
                sum1[i] = sum1[i - 1];
            } else {
                sum1[i] = i;
            }

            if (i >= k * 2 - 1) {
                int tmpsum = presum[i] + presum[sum1[i - k]];
                if (tmpsum > presum[sum2[i - 1].first] + presum[sum2[i - 1].second]) {
                    sum2[i] = pair<int, int>(sum1[i - k], i);
                } else {
                    sum2[i] = sum2[i - 1];
                }
            }

            if (i >= k * 3 - 1) {
                int tmpsum = presum[i] + presum[sum2[i - k].first] + presum[sum2[i - k].second];
                //cout << i << " " << tmpsum << endl;
                if (tmpsum > maxn) {                   
                    maxn = tmpsum;
                    res = {sum2[i - k].first - k + 1, sum2[i - k].second - k + 1, i - k + 1};
                } else if (tmpsum == maxn) {
                    int r1 = sum2[i - k].first - k + 1;
                    int r2 = sum2[i - k].second - k + 1;
                    int r3 = i - k + 1;
                    if (r1 < res[0] || (r1 == res[0] && r2 < res[1]) || (r1 == res[0] && r2 == res[1] && r3 < res[2])) {
                        res = {r1, r2, r3};
                    }
                }
            }
        }
        

        return res;
    }
};
