class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        if (s[0] == '0') return 0;
        if (len == 1) return 1;
        int dp[len + 5];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        //if (len == 2) {
            if (s[1] == '0') {
                if (s[0] == '1' || s[0] == '2') dp[1] = 1;
                else return 0;
            } else if (s[0] == '1') dp[1] = 2;
            else if (s[0] == '2' && s[1] <= '6') dp[1] = 2;
            else dp[1] = 1;
        //}
        
        
        for (int i = 2; i < len; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') dp[i] = dp[i - 2];
                else return 0;
            } else if (s[i - 1] == '1') {
                dp[i] = dp[i - 1];
                dp[i] += dp[i - 2];
            } else if (s[i - 1] == '2') {
                dp[i] = dp[i - 1];
                if (s[i] <= '6') {
                    dp[i] += dp[i - 2];
                } 
            } else dp[i] = dp[i - 1];
        }   
        return dp[len - 1];
    }
};
