class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row <= 0) return 0;
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) res += count(grid, i, j, row, col);
            }
        }
        return res;
    }

    int count(vector<vector<int>>& grid, int i, int j, int row, int col) {
        int res = 0;
        if (i > 0) res += (grid[i - 1][j] == 0 ? 1 : 0);
        else res++;
        if (j > 0) res += (grid[i][j - 1] == 0 ? 1 : 0);
        else res++;
        if (i < row - 1) res += (grid[i + 1][j] == 0 ? 1 : 0);
        else res++;
        if (j < col - 1) res += (grid[i][j + 1] == 0 ? 1 : 0);
        else res++;
        return res;
    }
};
