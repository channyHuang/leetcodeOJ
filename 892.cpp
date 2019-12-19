class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        int res = 0;
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) count++;
                //up
                if (i == 0) res += grid[i][j];
                else if (grid[i - 1][j] < grid[i][j]) res += (grid[i][j] - grid[i - 1][j]);
                //down
                if (i == rows - 1) res += grid[i][j];
                else if (grid[i + 1][j] < grid[i][j]) res += grid[i][j] - grid[i + 1][j];
                //left
                if (j == 0) res += grid[i][j];
                else if (grid[i][j - 1] < grid[i][j]) res += grid[i][j] - grid[i][j - 1];
                //right
                if (j == cols - 1) res += grid[i][j];
                else if (grid[i][j + 1] < grid[i][j]) res += grid[i][j] - grid[i][j + 1];
            }
        }
        res += ((rows * cols - count) << 1);

        return res;
    }
};
