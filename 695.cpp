class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        maxn = 0;
        vector<vector<bool>> used;
        for (int i = 0; i < rows; i++) {
            vector<bool> subused;
            subused.resize(cols);
            used.push_back(subused);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                int count = 1;
                search(grid, used, rows, cols, i, j, count);
                if (maxn < count) maxn = count;
            }
        }
        return maxn;
    }

    void search(vector<vector<int>>& grid, vector<vector<bool>>& used, int& rows, int& cols, int r, int c, int& count) {
        used[r][c] = true;
        if (r > 0 && !used[r - 1][c] && grid[r - 1][c] == 1) search(grid, used, rows, cols, r - 1, c, ++count);
        if (r < rows - 1 && !used[r + 1][c] && grid[r + 1][c] == 1) search(grid, used, rows, cols, r + 1, c, ++count);
        if (c > 0 && !used[r][c - 1] && grid[r][c - 1] == 1) search(grid, used, rows, cols, r, c - 1, ++count);
        if (c < cols - 1 && !used[r][c + 1] && grid[r][c + 1] == 1) search(grid, used, rows, cols, r, c + 1, ++count);
    }

private:
    int maxn;
};
