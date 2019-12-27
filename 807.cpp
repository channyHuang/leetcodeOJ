class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        int res = 0;
        int maxrow[rows] = {0};
        int maxcol[cols] = {0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (maxrow[i] < grid[i][j]) {
                    maxrow[i] = grid[i][j];
                }
                if (maxcol[j] < grid[i][j]) {
                    maxcol[j] = grid[i][j];
                }
            }  
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res += min(maxrow[i], maxcol[j]) - grid[i][j];
            }
        }
        return res;
    }
};
