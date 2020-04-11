class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int count = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                vector<int> sub;
                sub.push_back(nums1[i]);
                sub.push_back(nums2[j]);
                int sum = nums1[i] + nums2[j];
                if (count < k) {
                    res.push_back(sub);
                    int idx = count;
                    int pidx = (count - 1) / 2;
                    while (pidx >= 0) {
                        if (res[pidx][0] + res[pidx][1] < sum) {
                            vector<int> tmp = res[idx];
                            res[idx] = res[pidx];
                            res[pidx] = tmp;
                            idx = pidx;
                            pidx = (idx - 1) / 2;
                        } else break;
                    }
                    count++;
                } else if (sum >= res[0][0] + res[0][1]) {
                    continue;
                } else {
                    res[0] = sub;
                    int idx = 0;
                    int pidx = idx * 2 + 1;
                    while (pidx < count) {
                        if (pidx + 1 < count && res[pidx + 1][0] + res[pidx + 1][1] > res[pidx][0] + res[pidx][1]) pidx++;
                        if (res[pidx][0] + res[pidx][1] > sum) {
                            vector<int> tmp = res[pidx];
                            res[pidx] = res[idx];
                            res[idx] = tmp;
                            idx = pidx;
                            pidx = idx * 2 + 1;
                        } else break;
                    }
                }
            }
        }
        return res;
    }
};
