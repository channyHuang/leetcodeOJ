class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0) return 0;
        int cols = matrix[0].size();
        if (cols <= 0) return 0;
        int maxrow[rows][cols];
        int maxcol[rows][cols];
        int res = 0;
        memset(maxrow, 0, sizeof(maxrow));
        memset(maxcol, 0, sizeof(maxcol));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') continue;
                maxrow[i][j] = (j == 0 ? 1 : maxrow[i][j - 1] + 1);
                maxcol[i][j] = (i == 0 ? 1 : maxcol[i - 1][j] + 1);
                int maxc = maxrow[i][j];
                for (int r = 0; r <= i; r++) {
                    maxc = min(maxc, maxrow[i - r][j]);
                    res = max(res, maxc * (r + 1));
                }
            }
        }
        return res;
    }
};
