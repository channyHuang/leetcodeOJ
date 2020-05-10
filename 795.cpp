class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int len = A.size();
        int dp[len];
        memset(dp, 0, sizeof(dp));
        int stPos = -1;
        int maxIdx = -1;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] < L) {
                if (maxIdx == -1) continue;
                res += (maxIdx - stPos);
            } else if (A[i] > R) {
                stPos = i;
                maxIdx = -1;
                continue;
            } else {
                maxIdx = i;
                res += (i - stPos);
            }
        }
        return res;
    }
};
