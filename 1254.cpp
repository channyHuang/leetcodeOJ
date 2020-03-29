class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) continue;
                bool flag = true;
                search(grid, rows, cols, i, j, flag);
                if (flag) res++;
            }
        }
        return res;
    }

    void search(vector<vector<int>>& grid, int& rows, int& cols, int r, int c, bool& flag) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        if (grid[r][c] != 0) return;
        grid[r][c] = 2;
        if (flag && (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)) flag = false;
        if (r > 0) search(grid, rows, cols, r - 1, c, flag);
        if (c > 0) search(grid, rows, cols, r, c - 1, flag);
        if (r < rows - 1) search(grid, rows, cols, r + 1, c, flag);
        if (c < cols - 1) search(grid, rows, cols, r, c + 1, flag);
    }
};
