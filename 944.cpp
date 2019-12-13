class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int rows = A.size();
        int cols = A[0].length();
        int res = 0;
        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                if (A[r][c] < A[r - 1][c]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
