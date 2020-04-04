class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        bool used[20][20];
        memset(used, 0, sizeof(used));
        res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                used[i][j] = true;
                search(grid, used, rows, cols, i, j, grid[i][j]);
                used[i][j] = false;
            }
        }
        return res;
    }

    void search(vector<vector<int>>& grid, bool used[20][20], int rows, int cols, int r, int c, int curSum) {
        if (res < curSum) res = curSum;

        if (r > 0 && grid[r - 1][c] != 0 && !used[r - 1][c]) {
            used[r - 1][c] = true;
            search(grid, used, rows, cols, r - 1, c, curSum + grid[r - 1][c]);
            used[r - 1][c] = false;
        }
        if (r < rows - 1 && grid[r + 1][c] != 0 && !used[r + 1][c]) {
            used[r + 1][c] = true;
            search(grid, used, rows, cols, r + 1, c, curSum + grid[r + 1][c]);
            used[r + 1][c] = false;
        }
        if (c > 0 && grid[r][c - 1] != 0 && !used[r][c - 1]) {
            used[r][c - 1] = true;
            search(grid, used, rows, cols, r, c - 1, curSum + grid[r][c - 1]);
            used[r][c - 1] = false;
        }
        if (c < cols - 1 && grid[r][c + 1] != 0 && !used[r][c + 1]) {
            used[r][c + 1] = true;
            search(grid, used, rows, cols, r, c + 1, curSum + grid[r][c + 1]);
            used[r][c + 1] = false;
        }
    }

private:
    int res;
};
