class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0;
        int len = A.size();
        if (K > len) return -1;
        if (K == 1) return (len - std::accumulate(A.begin(), A.end(), 0));
        std::vector<int> count(len + 1, 0);
        int curCount = 0;
        for (int i = 0; i <= len - K; i++) {
            curCount += count[i];
            int tmp = A[i];
            if (curCount & 1) tmp = 1 - tmp;
            if (tmp == 0) {
                res++;
                count[i]++;
                curCount++;
                count[i + K]--;
            }
        }
        for (int i = len - K + 1; i < len; i++) {
            curCount += count[i];
            int tmp = A[i];
            if (curCount & 1) tmp = 1 - tmp;
            if (tmp == 0) return -1;
        }
        return res;
    }
};
