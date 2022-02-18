class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int len = str.length();
        if (len <= 1) return 1;
        vector<int> dp(len, 0);
        dp[0] = 1;
        if (str[0] > '2') dp[1] = 1;
        else if (str[0] == '0') dp[1] = 1;
        else if (str[0] == '2' && str[1] > '5') dp[1] = 1;
        else dp[1] = 2;
        for (int i = 2; i < len; ++i) {
            if (str[i - 1] > '2') {
                dp[i] = dp[i - 1];
                continue;
            } 
            if (str[i - 1] == '0') {
                dp[i] = dp[i - 1];
                continue;
            }
            if (str[i - 1] == '2') {
                if (str[i] > '5') {
                    dp[i] = dp[i - 1];
                    continue;
                }
            }
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[len - 1];
    }
};
