class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int AU = 0;
        int AD = 1;
        int BU = 1;
        int BD = 0;
        int len = A.size();
        int res = len;
        int i;
        for (i = 1; i < len; i++) {
            if (A[i] != A[0] && B[i] != A[0]) break;
            if (A[i] != A[0] && B[i] == A[0]) AU++;
            if (B[i] != A[0] && A[i] == A[0]) AD++;
        }
        if (i == len) res = min(res, min(AU, AD));
        for (i = 1; i < len; i++) {
            if (A[i] != B[0] && B[i] != B[0]) break;
            if (B[i] != B[0] && A[i] == B[0]) BD++;
            if (A[i] != B[0] && B[i] == B[0]) BU++;
        }
        if (i == len) {
            res = min(res, min(BU, BD));
        }
        return (res == len ? -1 : res);
    }
};