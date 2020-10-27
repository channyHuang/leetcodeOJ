class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int len = envelopes.size();
        vector<int> dp(len, 1);
        vector<int> lastIdx(len);
        for (int i = 0; i < len; i++) {
            lastIdx[i] = -1;
        }
        for (int i = 1; i < len; i++) {
            int stPos = 0;
            for (int j = i - 1; j >= stPos; j--) {
                if (envelopes[j][0] == envelopes[i][0] || envelopes[j][1] >= envelopes[i][1]) continue;
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    lastIdx[i] = j;
                    //stPos = max(stPos, lastIdx[j]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }

    bool static cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
