class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        rows = matrix.size();
        if (rows <= 0) return 0;
        cols = matrix[0].size();
        if (cols <= 0) return 0;
        int presum[rows + 1][cols + 1];
        memset(presum, 0, sizeof(presum));
        //vector<vector<int>> presum(rows + 1, vector<int>(cols + 1, 0));
        int res = 0;

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                presum[i][j] = matrix[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];

                for (int left = 0; left < j; left++) {
                    for (int up = 0; up < i; up++) {
                        int tmp = presum[i][j] - presum[i][left] - presum[up][j] + presum[up][left];
                        if (tmp == target) res++;
                    }
                }
            }
        }
        return res;
    }

private:
    int rows;
    int cols;
};
