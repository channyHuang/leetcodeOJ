class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int len = A.size();
        if (len == 1) return 0;
        sort(A.begin(), A.end());
        int res = A[len - 1] - A[0];
        for (int i = 0; i < len - 1; i++) {
            int maxn = max(A[i] + K, A[len - 1] - K);
            int minn = min(A[0] + K, A[i + 1] - K);
            res = min(res, maxn - minn);
        }
        return res;
    }
};
