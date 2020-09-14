class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lena = A.size();
        int lenb = B.size();
        int res = 0;
        for (int i = 0; i < lena - res; i++) {
            for (int j = 0; j < lenb - res; j++) {
                if (A[i] != B[j]) continue;
                int cnt = 1;
                while (i + cnt < lena && j + cnt < lenb && (A[i + cnt] == B[j + cnt])) cnt++;
                //cout << i << " " << j << " " << cnt << endl;
                res = max(res, cnt);
            }
        }
        return res;
    }
};
