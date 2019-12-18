class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0) return true;
        int cols = matrix[0].size();
        if (cols <= 0) return true;
        for (int r = rows - 1; r >= 0; r--) {
            for (int i = 1; i < cols; i++) {
                if (r + i >= rows) break;
                if (matrix[r + i][i] != matrix[r][0]) return false;
            }
        }
        for (int c = 1; c < cols; c++) {
            for (int i = 1; i < rows; i++) {
                if (c + i >= cols) break;
                if (matrix[i][c + i] != matrix[0][c]) return false;
            }
        }
        return true;
    }
};
