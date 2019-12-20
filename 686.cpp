class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int posa = 0, posb = 0;
        int lena = A.length(), lenb = B.length();
        bool count[256];
        memset(count, false, sizeof(count));
        for (int i = 0; i < lena; i++) {
            count[A[i]] = true;
        }
        for (int i = 0; i < lenb; i++) {
            if (count[B[i]] == 0) return -1;
        }
        int res = 0;
        while (posa < lena) {
            while (1) {
                while (posa < lena && A[posa] != B[0]) posa++;
                if (posa >= lena) return -1;
                int x = posa, y = 0;
                while(A[x] == B[y]) {
                    x++;
                    y++;
                    if (x >= lena) break;
                    if (y >= lenb) break;
                }
                if (x == lena || y == lenb) break;
                else posa++;
            }
            res = 1;
            int i = 0;
            int curpos = posa;
            for (i = 0; i < lenb; i++) {
                if (curpos >= lena) {
                    curpos = 0;
                    res++;
                }
                if (A[curpos] != B[i]) {
                    posa++;
                    break;
                }
                curpos++;
            }
            if (i >= lenb) return res;
        }

        return -1;
    }
};
