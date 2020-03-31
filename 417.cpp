class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {      
        int rows = matrix.size();
        if (rows <= 0) return res;
        int cols = matrix[0].size();
        if (cols <= 0) return res;
        vector<vector<int>> flag;
        for (int i = 0; i < rows; i++) {
            vector<int> subflag;
            subflag.resize(cols);
            flag.push_back(subflag);
        }
        for (int j = 0; j < cols; j++) {
            seach(matrix, flag, rows, cols, 0, j, 1);
            seach(matrix, flag, rows, cols, rows - 1, j, 2);
        }
        for (int i = 0; i < rows; i++) {
            seach(matrix, flag, rows, cols, i, 0, 1);
            seach(matrix, flag, rows, cols, i, cols - 1, 2);
        }
        return res;
    }

    void seach(vector<vector<int>>& matrix, vector<vector<int>>& flag, int& rows, int& cols, int r, int c, int setFlag) {
        queue<pair<int, int>> qu;
        qu.push(pair<int, int>(r, c));
        while (!qu.empty()) {
            pair<int, int> curPair = qu.front();
            qu.pop();
            if (flag[curPair.first][curPair.second] == setFlag || flag[curPair.first][curPair.second] == 4) continue;
            if (flag[curPair.first][curPair.second] != 0) {
                vector<int> subres;
                subres.push_back(curPair.first);
                subres.push_back(curPair.second);
                res.push_back(subres);
                flag[curPair.first][curPair.second] = 4;
            }
            else flag[curPair.first][curPair.second] = setFlag;
            if (curPair.first > 0 && flag[curPair.first - 1][curPair.second] != setFlag && flag[curPair.first - 1][curPair.second] != 4 && matrix[curPair.first - 1][curPair.second] >= matrix[curPair.first][curPair.second]) {
                qu.push(pair<int, int>(curPair.first - 1, curPair.second));
            }
            if (curPair.first < rows - 1 && flag[curPair.first + 1][curPair.second] != setFlag && flag[curPair.first + 1][curPair.second] != 4 && matrix[curPair.first + 1][curPair.second] >= matrix[curPair.first][curPair.second]) {
                qu.push(pair<int, int>(curPair.first + 1, curPair.second));
            }
            if (curPair.second > 0 && flag[curPair.first][curPair.second - 1] != setFlag && flag[curPair.first][curPair.second - 1] != 4 && matrix[curPair.first][curPair.second - 1] >= matrix[curPair.first][curPair.second]) {
                qu.push(pair<int, int>(curPair.first, curPair.second - 1));
            }
            if (curPair.second < cols - 1 && flag[curPair.first][curPair.second + 1] != setFlag && flag[curPair.first][curPair.second + 1] != 4 && matrix[curPair.first][curPair.second + 1] >= matrix[curPair.first][curPair.second]) {
                qu.push(pair<int, int>(curPair.first, curPair.second + 1));
            }
        }
    }

private:
    vector<vector<int>> res;
};
