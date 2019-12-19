class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int len = A.size();
        int minabs = 0;
        if (len == 0) return 0;
        if (len == 1) return (K & 1) ? -A[0] : A[0];
        sort(A.begin(), A.end());
        int negitive = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] >= 0) {
                if (negitive) minabs = min(A[i], -A[i - 1]);
                else minabs = A[i];
                break;
            }
            negitive++;
        }
        int res = 0;
        if (negitive >= K) {
            for (int i = 0; i < len; i++) {
                if (i < K) res -= A[i];
                else res += A[i];
            }
        } else {
            K -= negitive;
            for (int i = 0; i < len; i++) {
                res += (A[i] >= 0 ? A[i] : -A[i]);
            }
            if (K & 1) {
                res -= minabs;
                res -= minabs;
            }
        }
        return res;
    }
};
