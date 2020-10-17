class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows <= 0) return 0;
        cols = matrix[0].size();
        if (cols <= 0) return 0;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int res = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dp[i][j] > 0) {
                    res = max(res, dp[i][j]);
                    continue;
                }
                search(matrix, dp, i, j);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }

    void search(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
        dp[row][col] = 1;
        if (row > 0 && matrix[row][col] < matrix[row - 1][col]) {
            if (dp[row - 1][col] <= 0) search(matrix, dp, row - 1, col);
            dp[row][col] = max(dp[row][col], dp[row - 1][col] + 1);
        }
        if (col > 0 && matrix[row][col] < matrix[row][col - 1]) {
            if (dp[row][col - 1] <= 0) search(matrix, dp, row, col - 1);
            dp[row][col] = max(dp[row][col], dp[row][col - 1] + 1);
        }
        if (row < rows - 1 && matrix[row][col] < matrix[row + 1][col]) {
            if (dp[row + 1][col] <= 0) search(matrix, dp, row + 1, col);
            dp[row][col] = max(dp[row][col], dp[row + 1][col] + 1);
        }
        if (col < cols - 1 && matrix[row][col] < matrix[row][col + 1]) {
            if (dp[row][col + 1] <= 0) search(matrix, dp, row, col + 1);
            dp[row][col] = max(dp[row][col], dp[row][col + 1] + 1);
        }
    }

private:
    int rows, cols;
};
