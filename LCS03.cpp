class Solution {
public:
    int largestArea(vector<string>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        vector<vector<bool>> used(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (used[i][j]) continue;
                if (grid[i][j] == '0') continue;
                bool valid = true;
                int area = 1;
                search(grid, used, i, j, valid, grid[i][j], area);
                if (valid && area > res) {
                    //cout << i << ", " << j << " : "<< valid << endl;
                    res = area;
                }
            }
        }
        return res;
    }

    void search(vector<string>& grid, vector<vector<bool>>& used, int r, int c, bool& valid, char target, int& area) {
        used[r][c] = true;
        if (valid) {
            if (r == 0 || r == row - 1 || c == 0 || c == col) valid = false;
            if (r > 0 && grid[r - 1][c] == '0') valid = false;
            if (c > 0 && grid[r][c - 1] == '0') valid = false;
            if (r < row - 1 && grid[r + 1][c] == '0') valid = false;
            if (c < col - 1 && grid[r][c + 1] == '0') valid = false;
        }

        if (r > 0 && !used[r - 1][c] && grid[r - 1][c] == target) {
            search(grid, used, r - 1, c, valid, target, ++area);
        }
        if (r < row - 1 && !used[r + 1][c] && grid[r + 1][c] == target) {
            search(grid, used, r + 1, c, valid, target, ++area);
        }
        if (c > 0 && !used[r][c - 1] && grid[r][c - 1] == target) {
            search(grid, used, r, c - 1, valid, target, ++area);
        }
        if (c < col - 1 && !used[r][c + 1] && grid[r][c + 1] == target) {
            search(grid, used, r, c + 1, valid, target, ++area);
        }
    }
private:
    int row, col;
};
