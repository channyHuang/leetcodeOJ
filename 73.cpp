class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0) return;
        int cols = matrix[0].size();
        if (cols <= 0) return;

        bool flagr[rows] = {0};
        bool flagc[cols] = {0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) continue;
                flagr[i] = true;
                flagc[j] = true;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (flagr[i] || flagc[j]) matrix[i][j] = 0;
            }
        }
    }
};
