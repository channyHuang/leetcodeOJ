class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        queue<pair<int, int>> qu;
        int next = mat2int(mat);
        reach.insert(next);
        qu.push(pair<int, int>(next, 0));
        while (!qu.empty()) {
            pair<int, int> cur = qu.front();
            qu.pop();
            if (cur.first == 0) return cur.second;
            
            vector<vector<int>> curmat = int2mat(cur.first);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    revert(curmat, i, j);
                    next = mat2int(curmat);
                    if (reach.find(next) != reach.end()) {
                        revert(curmat, i, j);
                        continue;
                    }
                    reach.insert(next);
                    qu.push(pair<int, int>(next, cur.second + 1));
                    revert(curmat, i, j);
                }
            }
        }
        return -1;
    }

    void revert(vector<vector<int>>& mat, int i, int j) {
        mat[i][j] ^= 1;
        if (i - 1 >= 0) mat[i - 1][j] ^= 1;
        if (i + 1 < rows) mat[i + 1][j] ^= 1;
        if (j - 1 >= 0) mat[i][j - 1] ^= 1;
        if (j + 1 < cols) mat[i][j + 1] ^= 1;
    }

    int mat2int(vector<vector<int>>& mat) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res |= (mat[i][j] << cnt);
                cnt++;
            }
        }
        return res;
    }

    vector<vector<int>> int2mat(int n) {
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        int cnt = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = ((n >> cnt) & 1);
                cnt++;
            }
        }
        return res;
    }

private:
    int rows, cols;
    unordered_set<int> reach;
};
