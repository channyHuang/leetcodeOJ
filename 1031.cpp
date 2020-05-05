class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int len = A.size();
        int lsum[len], msum[len];
        memset(lsum, 0, sizeof(lsum));
        memset(msum, 0, sizeof(msum));
        lsum[0] = A[0];
        msum[0] = A[0];
        for (int i = 1; i < len; i++) {
            lsum[i] = lsum[i - 1] + A[i];
            if (i >= L) lsum[i] -= A[i - L];
            msum[i] = msum[i - 1] + A[i];
            if (i >= M) msum[i] -= A[i - M];
        }
        int res = 0;
        for (int i = L - 1; i < len; i++) {
            for (int j = i - L; j >= M - 1; j--) {
                res = max(res, lsum[i] + msum[j]);
            }
            for (int j = i + M; j < len; j++) {
                res = max(res, lsum[i] + msum[j]);
            }
        }
        return res;
    }
};
