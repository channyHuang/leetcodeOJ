class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int len = p.length();
        if (len <= 1) return len; 
        vector<int> dp(26, 0);
        dp[p[0] - 'a'] = 1;
        int tmp = 1;
        for (int i = 1; i < len; i++) {
            if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
                tmp++;
            } else tmp = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], tmp);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
