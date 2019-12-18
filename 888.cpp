class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int lena = A.size(), lenb = B.size();
        int suma = 0, sumb = 0;
        vector<int> res;
        for (int i = 0; i < lena; i++) suma += A[i];
        for (int i = 0; i < lenb; i++) sumb += B[i];
        int diff = suma - sumb;
        sort(B.begin(), B.end());
        int idx = -1;
        for (int i = 0; i < lena; i++) {
            idx = find(B, A[i] - diff / 2);
            if (idx != -1) {
                res.push_back(A[i]);
                res.push_back(B[idx]);
                return res;
            }
        }
        return res;
    }

    int find(vector<int> &B, int target) {
        int stPos = 0, endPos = B.size() - 1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (B[midPos] == target) return midPos;
            else if (B[midPos] < target) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return -1;
    }
};
