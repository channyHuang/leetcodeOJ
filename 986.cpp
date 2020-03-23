class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int lena = A.size(), lenb = B.size();
        int posa = 0, posb = 0;
        while (posa < lena && posb < lenb) {
            if (A[posa][1] < B[posb][0]) {
                posa++;
                continue;
            }
            if (B[posb][1] < A[posa][0]) {
                posb++;
                continue;
            }
            {
                vector<int> sub;
                sub.push_back(max(A[posa][0], B[posb][0]));
                sub.push_back(min(A[posa][1], B[posb][1]));
                res.push_back(sub);
            }
            if (A[posa][1] < B[posb][1]) posa++;
            else posb++;
        }
        return res;
    }
};
