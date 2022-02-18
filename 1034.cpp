class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        search(grid, row, col, color, used, grid[row][col]);
        return grid;
    }

    void search(vector<vector<int>>& grid, int r, int c, int color, vector<vector<bool>> &used, int targetcolor) {
        if (used[r][c]) return;
        used[r][c] = true;
        bool isbord = false;
        if (r <= 0 || c <= 0 || r >= rows - 1 || c >= cols - 1) isbord = true;
        if (r > 0 && !used[r - 1][c]) {
            if (grid[r - 1][c] == targetcolor) {
                search(grid, r - 1, c, color, used, targetcolor);
            } else {
                isbord = true;
            }
        }
        if (r < rows - 1 && !used[r + 1][c]) {
            if (grid[r + 1][c] == targetcolor) {
                search(grid, r + 1, c, color, used, targetcolor);
            } else {
                isbord = true;
            }
        }
        if (c > 0 && !used[r][c - 1]) {
            if (grid[r][c - 1] == targetcolor) {
                search(grid, r, c - 1, color, used, targetcolor);
            } else {
                isbord = true;
            }
        }
        if (c < cols - 1 && !used[r][c + 1]) {
            if (grid[r][c + 1] == targetcolor) {
                search(grid, r, c + 1, color, used, targetcolor);
            } else {
                isbord = true;
            }
        }
        if (isbord) {
            grid[r][c] = color;
        }
    }

private:
    int rows, cols;
};
