class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> res;
        vector<int> minsum;
        res.resize(n);
        for (int i = 0; i < n; ++i) {
            int len = 5 * (i + 1) + 1;
            res[i].resize(len, 0);
            minsum.push_back(i + 1);
            if (i == 0) {
                for (int x = 0; x < len; ++x) {
                    res[i][x] = 1;
                }
                continue;
            }
            for (int x = 0; x < len; ++x) {
                int expsum = minsum[i] + x;
                for (int k = 1; k <= 6; ++k) {
                    int presum = expsum - minsum[i - 1] - k;
                    if (presum >= 0 && presum < res[i - 1].size()) {
                        res[i][x] += res[i - 1][presum];
                    }
                }
            }
        }
        int total = std::pow(6, n);
        int tlen = 5 * n + 1;
        int halftlen = (tlen >> 1);
        vector<double> finres(tlen, 0);
        for (int i = 0; i <= halftlen; ++i) {
            finres[i] = res[n - 1][i] * 1.0 / total;
            finres[tlen - i - 1] = finres[i];
        }
        return finres;
    }
};
