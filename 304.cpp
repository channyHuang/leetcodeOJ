class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows <= 0) return;
        cols = matrix[0].size();
        if (cols <= 0) return;
        {
            vector<int> subres;
            int count = 0;
            subres.push_back(matrix[0][0]);
            for (int j = 1; j < cols; j++) {
                subres.push_back(subres[count] + matrix[0][j]);
                count++;
            }
            res.push_back(subres);
        }
        for (int i = 1; i < rows; i++) {
            vector<int> subres;
            subres.push_back(res[i - 1][0] + matrix[i][0]);
            for (int j = 1; j < cols; j++) {
                subres.push_back(res[i - 1][j] + subres[j - 1] - res[i - 1][j - 1] + matrix[i][j]);
            }
            res.push_back(subres);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row2 >= rows || col2 >= cols) return res[rows - 1][cols - 1];
        if (row1 == 0) {
            if (col1 == 0) return res[row2][col2];
            else return res[row2][col2] - res[row2][col1 - 1];
        } else {
            if (col1 == 0) return res[row2][col2] - res[row1 - 1][col2];
            else return res[row2][col2] - res[row1 - 1][col2] - res[row2][col1 - 1] + res[row1 - 1][col1 - 1];
        }
        return res[row2][col2];
    }

private:
    vector<vector<int>> res;
    int rows;
    int cols;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
