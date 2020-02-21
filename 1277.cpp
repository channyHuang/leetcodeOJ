class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         vector<vector<int>> res;
         int rows = matrix.size();
         int cols = matrix[0].size();
         for(int i = 0; i < rows; i++) {
             vector<int> subres;
             subres.resize(cols);
             res.push_back(subres);
         }
         int total = 0;
         for (int i = 0; i < rows; i++) {
             res[i][0] = matrix[i][0];
             total += res[i][0];
         }
         for (int j = 1; j < cols; j++) {
             res[0][j] = matrix[0][j];
             total += res[0][j];
         }
         for (int i = 1; i < rows; i++) {
             for (int j = 1; j < cols; j++) {
                 if (matrix[i][j] == 0) continue;
                 res[i][j] = 1;
                 int minn = res[i - 1][j];
                 if (res[i][j - 1] < minn) minn = res[i][j - 1];
                 if (res[i - 1][j - 1] < minn) minn = res[i - 1][j - 1];
                 if (minn == 0) {
                     total += 1;
                     continue;
                 }
                 res[i][j] = minn + 1;
                 total += res[i][j];
             }
         }
         return total;
    }
};