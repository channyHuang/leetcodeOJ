class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].length();
        if (cols <= 0) return 0;
        bool used[35][35][2]; //0: left, 1: right
        memset(used, 0, sizeof(used));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!used[i][j][0]) {
                    res++;
                    search(grid, used, rows, cols, i, j, 0);
                }
                if (!used[i][j][1]) {
                    res++;
                    search(grid, used, rows, cols, i, j, 1);
                }
            }
        }
        return res;
    }

    void search(vector<string>& grid, bool used[35][35][2], int& rows, int& cols, int r, int c, int idx) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        if (used[r][c][idx]) return;
        if (grid[r][c] == ' ') {
            used[r][c][0] = used[r][c][1] = true;
        } else {
            used[r][c][idx] = true;
        }
        if (grid[r][c] == ' ') {
            if (r > 0) {
                if (grid[r - 1][c] == ' ' || grid[r - 1][c] == '/') search(grid, used, rows, cols, r - 1, c, 1);
                else search(grid, used, rows, cols, r - 1, c, 0);
            }
            if (r < rows - 1) {
                if (grid[r + 1][c] == ' ' || grid[r + 1][c] == '/') search(grid, used, rows, cols, r + 1, c, 0);
                else search(grid, used, rows, cols, r + 1, c, 1);
            }
            if (c > 0) {
                if (grid[r][c - 1] == ' ' || grid[r][c - 1] == '/') search(grid, used, rows, cols, r, c - 1, 1);
                else search(grid, used, rows, cols, r, c - 1, 1);
            }
            if (c < cols - 1) {
                if (grid[r][c + 1] == ' ' || grid[r][c + 1] == '/') search(grid, used, rows, cols, r, c + 1, 0);
                else search(grid, used, rows, cols, r, c + 1, 0);
            }
        } else if (grid[r][c] == '/') {
            if (idx == 0) {
                if (r > 0) {
                    if (grid[r - 1][c] == ' ' || grid[r - 1][c] == '/') search(grid, used, rows, cols, r - 1, c, 1);
                    else search(grid, used, rows, cols, r - 1, c, 0);
                }
                if (c > 0) {
                    if (grid[r][c - 1] == ' ' || grid[r][c - 1] == '/') search(grid, used, rows, cols, r, c - 1, 1);
                    else search(grid, used, rows, cols, r, c - 1, 1);
                }
            } else {
                if (r < rows - 1) {
                    if (grid[r + 1][c] == ' ' || grid[r + 1][c] == '/') search(grid, used, rows, cols, r + 1, c, 0);
                    else search(grid, used, rows, cols, r + 1, c, 1);
                }
                if (c < cols - 1) {
                    if (grid[r][c + 1] == ' ' || grid[r][c + 1] == '/') search(grid, used, rows, cols, r, c + 1, 0);
                    else search(grid, used, rows, cols, r, c + 1, 0);
                }
            }
        } else {// grid[i][j] == '\'
            if (idx == 1) {
                if (r > 0) {
                    if (grid[r - 1][c] == ' ' || grid[r - 1][c] == '/') search(grid, used, rows, cols, r - 1, c, 1);
                    else search(grid, used, rows, cols, r - 1, c, 0);
                }
                if (c < cols - 1) {
                    if (grid[r][c + 1] == ' ' || grid[r][c + 1] == '/') search(grid, used, rows, cols, r, c + 1, 0);
                    else search(grid, used, rows, cols, r, c + 1, 0);
                }
                
            } else {
                if (c > 0) {
                    if (grid[r][c - 1] == ' ' || grid[r][c - 1] == '/') search(grid, used, rows, cols, r, c - 1, 1);
                    else search(grid, used, rows, cols, r, c - 1, 1);
                }
                if (r < rows - 1) {
                    if (grid[r + 1][c] == ' ' || grid[r + 1][c] == '/') search(grid, used, rows, cols, r + 1, c, 0);
                    else search(grid, used, rows, cols, r + 1, c, 1);
                }               
            }
        }
    }

private:
    int res;
};
