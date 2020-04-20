class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int len = A.size();
        int lenStr = A[0].size();
        int res = 0;
        bool del[lenStr];
        memset(del, 0, sizeof(del));
        while (1) {
            int i;
            for (i = 1; i < len; i++) {
                int j;
                for (j = 0; j < lenStr; j++) {
                    if (del[j]) continue;
                    if (A[i][j] > A[i - 1][j]) break;
                    if (A[i][j] < A[i - 1][j]) {
                        del[j] = true;
                        res++;
                        break;
                    }
                }
                if (j >= lenStr || A[i][j] > A[i - 1][j]) continue;
                else break;
            }
            if (i == len) break;
        }
        return res;
    }
};
