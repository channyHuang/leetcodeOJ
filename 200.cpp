class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0') continue;
                res++;
                search(grid, rows, cols, i, j);
            }
        }
        return res;
    }

    void search(vector<vector<char>>& grid, int rows, int cols, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        if (grid[r][c] == '0') return;
        grid[r][c] = '0';
        search(grid, rows, cols, r - 1, c);
        search(grid, rows, cols, r + 1, c);
        search(grid, rows, cols, r, c - 1);
        search(grid, rows, cols, r, c + 1);
    }
};
