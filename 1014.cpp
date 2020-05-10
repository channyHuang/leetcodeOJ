class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int len = A.size();
        int maxn = max(A[0], A[1] + 1);
        int res = A[1] + A[0] - 1;
        for (int i = 2; i < len; i++) {
            res = max(res, A[i] - i + maxn);
            maxn = max(maxn, A[i] + i);
        }
        return res;
    }
};
