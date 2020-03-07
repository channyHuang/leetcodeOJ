class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lena = A.size();
        int lenb = B.size();
        int f[lena][lenb];
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lenb; j++) {
                f[i][j] = 0;
            }
        }
        int maxn = 0;
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lenb; j++) {
                if (A[i] != B[j]) continue;
                f[i][j] = 1;
                for (int k = i - 1; k >= 0; k--) {
                    for (int l = j - 1; l >= 0; l--) {
                        if (k == i && j == l) continue;
                        if (f[i][j] < f[k][l] + 1) f[i][j] = f[k][l] + 1;
                        
                    }
                }
                if (maxn < f[i][j]) maxn = f[i][j];
            }
        }
        return maxn;
    }
};
