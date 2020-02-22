class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        if (rows <= 0) return 0;
        int cols = obstacleGrid[0].size();
        if (cols <= 0) return 0;

        if (obstacleGrid[0][0]) return 0;
        if (obstacleGrid[rows - 1][cols - 1]) return 0;
        long long res[rows][cols] = {0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = 0;
            }
        }
        res[0][0] = 1;
        for (int j = 1; j < cols; j++) {
            if (obstacleGrid[0][j]) break;
            res[0][j] = 1;
        }
        for (int i = 1; i < rows; i++) {
            if (obstacleGrid[i][0]) break;
            res[i][0] = 1;
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j]) {
                    res[i][j] = 0;
                    continue;
                }
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[rows - 1][cols - 1];
    }
};