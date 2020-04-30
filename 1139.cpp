class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        int dprow[rows][cols];
        int dpcol[rows][cols];
        memset(dprow, 0, sizeof(dprow));
        memset(dpcol, 0, sizeof(dpcol));
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                res = max(res, 1);
                if (j > 0) dprow[i][j] = dprow[i][j - 1] + 1;
                else dprow[i][j] = 1;
                if (i > 0) dpcol[i][j] = dpcol[i - 1][j] + 1;
                else dpcol[i][j] = 1;

                int maxLen = min(i, j) + 1;
                for (int k = res; k < maxLen; k++) {
                    if (dprow[i][j] <= k || dpcol[i][j] <= k) break;
                    if (dprow[i - k][j] <= k || dpcol[i][j - k] <= k) continue;
                    res = k + 1;
                }
            }
        }
        return res * res;
    }
};
