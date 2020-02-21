class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> res;
        int rows = mat.size();
        int cols = mat[0].size();
        for (int i = 0; i < rows; i++) {
            vector<int> subres;
            subres.resize(cols);
            res.push_back(subres);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= min(cols - 1, K); j++) {
                res[i][0] += mat[i][j];
            }
            for (int j = 1; j < cols; j++) {
                res[i][j] = res[i][j - 1];
                if (j - 1 - K >= 0 ) res[i][j] -= mat[i][j - 1 - K];
                if (j + K < cols) res[i][j] += mat[i][j + K];
            }
        }
        vector<vector<int>> fres;
        for (int i = 0; i < rows; i++) {
            vector<int> subfres;
            subfres.resize(cols);
            fres.push_back(subfres);
        }
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i <= min(rows - 1, K); i++) {
                fres[0][j] += res[i][j];
            }
            for (int i = 1; i < rows; i++) {
                fres[i][j] = fres[i - 1][j];
                if (i - 1 - K >= 0) fres[i][j] -= res[i - 1 - K][j];
                if (i + K < rows) fres[i][j] += res[i + K][j]; 
            }
        }
        return fres;
    }
};