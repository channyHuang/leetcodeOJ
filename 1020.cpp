class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (A[i][j] != 1) continue;
                int cnt = 0;
                hasBoard = false;
                search(A, i, j, rows, cols, cnt);
                if (!hasBoard) res += cnt;
            }
        }
        return res;
    }

    void search(vector<vector<int>>& A, int i, int j, int rows, int cols, int &cnt) {
        A[i][j] = 2;
        cnt++;
        if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) hasBoard = true;
        if (i > 0 && A[i - 1][j] == 1) search(A, i - 1, j, rows, cols, cnt);
        if (i < rows - 1 && A[i + 1][j] == 1) search(A, i + 1, j, rows, cols, cnt);
        if (j > 0 && A[i][j - 1] == 1) search(A, i, j - 1, rows, cols, cnt);
        if (j < cols - 1 && A[i][j + 1] == 1) search(A, i, j + 1, rows, cols, cnt);
    }

private:
    bool hasBoard;
};
