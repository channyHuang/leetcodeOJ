class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3) return 0;
        int res = 0;
		vector<unordered_map<long long, int>> dp(len);	
        dp[1][(long long)A[1] - A[0]] = 1;
        for (int j = 2; j < len; j++) {
            for (int i = 0; i < j; i++) {
				long long diff = (long long)A[j] - A[i];
				dp[j][diff]++;
                if (dp[i].count(diff)) {
                    dp[j][diff] += dp[i][diff];
                    res += dp[i][diff];
                }
			}
		}

        return res;
    }
};
