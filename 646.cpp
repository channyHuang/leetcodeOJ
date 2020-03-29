class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        if (len <= 1) return len;
        int dp[len];
        memset(dp, 0, sizeof(dp));
        sort(pairs.begin(), pairs.end(), cmp);
        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int maxn = 1;
        for (int i = 1; i < len; i++) {
            if (maxn < dp[i]) maxn = dp[i];
        }
        return maxn;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
