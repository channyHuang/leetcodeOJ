class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        res.resize(n);
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                res[i - 1] = i;
            }
            return res;
        }
        res[0] = 1;
        int diff = k;
        int i;
        for (i = 1; i < n; i++) {
            if (i % 2 == 1) res[i] = res[i - 1] + diff;
            else res[i] = res[i - 1] - diff;
            diff--;
            if (diff == 0) break;
        }
        for (int j = k + 2; j <= n; j++) {
            res[++i] = j;
        }
        return res;
    }
};
