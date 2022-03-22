class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int len = rides.size();
        sort(rides.begin(), rides.end(), cmp);
        vector<long long> dp(n + 2, 0);
        int pos = len - 1;
        for (int i = n; i >= 0; --i) {
            dp[i] = dp[i + 1];
            while (pos >= 0 && rides[pos][0] == i) {
                dp[i] = std::max(dp[i], rides[pos][1] - rides[pos][0] + rides[pos][2] + dp[rides[pos][1]]);
                pos--;
            }
        }
        return dp[0];
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) return a[2] > b[2];
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};
