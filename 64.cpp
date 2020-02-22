class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;

        long long res[rows][cols] = {0};
        res[0][0] = grid[0][0];
        for (int j = 1; j < cols; j++) {
            res[0][j] = res[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            res[i][0] = res[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
            }
        }
        return res[rows - 1][cols - 1];
    }
};