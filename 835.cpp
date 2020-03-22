class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int len = A.size();
        long long Anum[len] = {0}, Bnum[len] = {0};
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                Anum[i] = (Anum[i] << 1) + A[i][j];
                Bnum[i] = (Bnum[i] << 1) + B[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int Acnt = 0;
                int Bcnt = 0;
                for (int row = i; row < len; row++) {
                    long long tmp = ((Anum[row] << j) & Bnum[row - i]);
                    Acnt += count(tmp);
                    tmp = ((Bnum[row] << j) & Anum[row - i]);
                    Bcnt += count(tmp);
                }
                if (res < Acnt) res = Acnt;
                if (res < Bcnt) res = Bcnt;
            }
        }
        return res;
    }

    int count(long long n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            res++;
        }
        return res;
    }
};
