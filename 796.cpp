class Solution {
public:
    bool rotateString(string A, string B) {
        int lena = A.length();
        if (lena != B.length()) return false;
        if (lena == 0) return true;
        for (int i = 0; i < lena; i++) {
            int j = 0;
            for (; j < lena; j++) {
                if (A[j] != B[(i + j) % lena]) break;
            }
            if (j >= lena) return true;
        }
        return false;
    }
};
