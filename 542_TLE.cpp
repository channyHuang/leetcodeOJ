class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int rows = matrix.size();
        if (rows <= 0) return res;
        int cols = matrix[0].size();
        if (cols <= 0) return res;
        {
            for (int i = 0; i < rows; i++) {
                vector<int> sub;
                sub.resize(cols);
                res.push_back(sub);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) continue;
                res[i][j] = search(matrix, rows, cols, i, j);
            }
        }
        return res;
    }

    int search(vector<vector<int>>& matrix, int rows, int cols, int r, int c) {
        queue<pair<pair<int, int>, int>> qu;
        int res = 0;
        vector<vector<bool>> used;
        for (int i = 0; i < rows; i++) {
            vector<bool> sub;
            sub.resize(cols);
            used.push_back(sub);
        }
        pair<int, int> curPair(r, c);
        qu.push(pair<pair<int, int>, int>(curPair, 0));
        while (!qu.empty()) {
            pair<pair<int, int>, int> frontPair = qu.front();
            qu.pop();
            int nr = frontPair.first.first;
            int nc = frontPair.first.second;
            if (nr > 0) {
                if (matrix[nr - 1][nc] == 0) return frontPair.second + 1;
                if (!used[nr - 1][nc]) {
                    used[nr - 1][nc] = true;
                    pair<int, int> nextPair(nr - 1, nc);
                    qu.push(pair<pair<int, int>, int>(nextPair, frontPair.second + 1));
                }
            }
            if (nr < rows - 1) {
                if (matrix[nr + 1][nc] == 0) return frontPair.second + 1;
                if (!used[nr + 1][nc]) {
                    used[nr + 1][nc] = true;
                    pair<int, int> nextPair(nr + 1, nc);
                    qu.push(pair<pair<int, int>, int>(nextPair, frontPair.second + 1));
                }
            }
            if (nc > 0) {
                if (matrix[nr][nc - 1] == 0) return frontPair.second + 1;
                if (!used[nr][nc - 1]) {
                    used[nr][nc - 1] = true;
                    pair<int, int> nextPair(nr, nc - 1);
                    qu.push(pair<pair<int, int>, int>(nextPair, frontPair.second + 1));
                }
            }
            if (nc < cols - 1) {
                if (matrix[nr][nc + 1] == 0) return frontPair.second + 1;
                if (!used[nr][nc + 1]) {
                    used[nr][nc + 1] = true;
                    pair<int, int> nextPair(nr, nc + 1);
                    qu.push(pair<pair<int, int>, int>(nextPair, frontPair.second + 1));
                }
            }
        }
        return 0;
    }
};
