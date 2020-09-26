class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows <= 0) return res;
        cols = matrix[0].size();
        if (cols <= 0) return res;
        res.resize(rows, vector<int>(cols, 0));
        queue<pair<int, int>> qu;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    res[i][j] = INT_MAX;
                } else {
                    qu.push(make_pair(i, j));
                }
            }
        }
        while (!qu.empty()) {
            pair<int, int> pa = qu.front();
            int i = pa.first;
            int j = pa.second;
            qu.pop();
            if (i > 0 && res[i - 1][j] > res[i][j] + 1) {
                res[i - 1][j] = res[i][j] + 1;
                qu.push(make_pair(i - 1, j));
            }
            if (i < rows - 1 && res[i + 1][j] > res[i][j] + 1) {
                res[i + 1][j] = res[i][j] + 1;
                qu.push(make_pair(i + 1, j));
            }
            if (j > 0 && res[i][j - 1] > res[i][j] + 1) {
                res[i][j - 1] = res[i][j] + 1;
                qu.push(make_pair(i, j - 1));
            }
            if (j < cols - 1 && res[i][j + 1] > res[i][j] + 1) {
                res[i][j + 1] = res[i][j] + 1;
                qu.push(make_pair(i, j + 1));
            }
        }
        return res;
    }

private:
    int rows, cols;
    vector<vector<int>> res;
};
