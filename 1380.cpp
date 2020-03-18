class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        int rows = matrix.size();
        int cols = matrix[0].size();       
        vector<int> rowMin;
        rowMin.resize(rows);
        vector<int> colMax;
        colMax.resize(cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] < matrix[i][rowMin[i]]) rowMin[i] = j;
                if (matrix[i][j] > matrix[colMax[j]][j]) colMax[j] = i;
            }
        }
        for (int i = 0; i < rows; i++) {
            if (i == colMax[rowMin[i]]) res.push_back(matrix[i][rowMin[i]]);
        }
        return res;
    }
};
