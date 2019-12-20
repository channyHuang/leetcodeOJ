class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        for (int i = 0; i < rows; i++) {
            int maxrow = 0;
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) res++;
                if (grid[i][j] > maxrow) maxrow = grid[i][j];
            }
            res += maxrow;
        }
        for (int j = 0; j < cols; j++) {
            int maxcol = grid[0][j];
            for (int i = 1; i < rows; i++) {
                if (grid[i][j] > maxcol) maxcol = grid[i][j];
            }
            res += maxcol;
        }
        return res;
    }
};
