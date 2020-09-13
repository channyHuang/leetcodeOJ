class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int len = arr.size();
        // end with arr[i]
        vector<long long> dp(len, 0);
        if (arr[0] & 1) {
            dp[0] = 1;
            oddIdx.push_back(0);
        }
        long long res = dp[0];
        for (int i = 1; i < len; i++) {
            if (arr[i] & 1) {
                oddIdx.push_back(i);
                int j = oddIdx.size() - 1;
                int tmp = (j >= 1 ? oddIdx[j] - oddIdx[j - 1] : oddIdx[j] + 1);
                dp[i] += tmp;
                for (j -= 2; j >= 0; j -= 2) {
                    dp[i] += dp[oddIdx[j]];
                    dp[i] %= maxn;
                    break;
                }
                dp[i] %= maxn;
            } else {
                dp[i] = dp[i - 1];
            }
            res += dp[i];
            res %= maxn;
        }
        return res;
    }
private:
    vector<int> oddIdx;
    int maxn = 1000000007;
};
