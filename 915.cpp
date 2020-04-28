class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int len = A.size();
        int minn = A[0];
        int stPos = 0;
        int maxn = A[0];
        for (int i = 1; i < len; i++) {
            if (minn > A[i]) {
                minn = A[i];
                stPos = i;
            }
        }
        for (int i = 1; i <= stPos; i++) {
            if (maxn < A[i]) maxn = A[i];
        }
        int endPos = len - 1;
        while (stPos < endPos) {
            if (A[endPos] < maxn) {
                for (int j = stPos; j <= endPos; j++) {
                    maxn = max(maxn, A[j]);
                }
                stPos = endPos;
                endPos = len - 1;
            } else endPos--;
        }
        return stPos + 1;
    }
};
