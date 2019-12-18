class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row <= 0) return -1;
        int col = grid[0].size();
        if (col <= 0) return -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != 2) continue;
                fill(grid, i, j, row, col);
            }
        }
        int res = 2;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 2) res = max(res, grid[i][j]);
                if (grid[i][j] == 1) return -1;
            }
        }
        return res - 2;
    }

    void fill(vector<vector<int>>& grid, int x, int y, int row, int col) {
        if (grid[x][y] == 0) return; 
        if (x + 1 < row) {
            if (grid[x + 1][y] == 1) {
                grid[x + 1][y] = grid[x][y] + 1;
                fill(grid, x + 1, y, row, col);
            }
            else if (grid[x + 1][y] > 2) {
                if (grid[x + 1][y] > grid[x][y] + 1) {
                    grid[x + 1][y] = grid[x][y] + 1;
                    fill(grid, x + 1, y, row, col);
                }
            }
        } 
        if (x - 1 >= 0) {
            if (grid[x - 1][y] == 1) {
                grid[x - 1][y] = grid[x][y] + 1;
                fill(grid, x - 1, y, row, col);
            }
            else if (grid[x - 1][y] > 2) {
                if (grid[x - 1][y] > grid[x][y] + 1) {
                    grid[x - 1][y] = grid[x][y] + 1;
                    fill(grid, x - 1, y, row, col);
                }
            }
        }
        if (y + 1 < col) {
            if (grid[x][y + 1] == 1) {
                grid[x][y + 1] = grid[x][y] + 1;
                fill(grid, x, y + 1, row, col);
            }
            else if (grid[x][y + 1] > 2) {
                if (grid[x][y + 1] > grid[x][y] + 1) {
                    grid[x][y + 1] = grid[x][y] + 1;
                    fill(grid, x, y + 1, row, col);
                }
            }
        }
        if (y - 1 >= 0) {
            if (grid[x][y - 1] == 1) {
                grid[x][y - 1] = grid[x][y] + 1;
                fill(grid, x, y - 1, row, col);
            }
            else if (grid[x][y - 1] > 2) {
                if (grid[x][y - 1] > grid[x][y] + 1) {
                    grid[x][y - 1] = grid[x][y] + 1;
                    fill(grid, x, y - 1, row, col);
                }
            }
        } 
    }
};
