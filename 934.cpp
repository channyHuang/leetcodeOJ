class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        queue<pair<int, int>> qu;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (A[i][j] == 0) continue;
                search(A, rows, cols, i, j, qu);
                break;
            }
            if (!qu.empty()) break;
        }

        while (!qu.empty()) {
            pair<int, int> curPair = qu.front();
            qu.pop();
            if (curPair.first > 0) {
                if (A[curPair.first - 1][curPair.second] == 0) {
                    qu.push(pair<int, int>(curPair.first - 1, curPair.second));
                    A[curPair.first - 1][curPair.second] = A[curPair.first][curPair.second] + 1;
                }
                else if (A[curPair.first - 1][curPair.second] == 1) return A[curPair.first][curPair.second] - 2;
            }
            if (curPair.first < rows - 1) {
                if (A[curPair.first + 1][curPair.second] == 0) {
                    qu.push(pair<int, int>(curPair.first + 1, curPair.second));
                    A[curPair.first + 1][curPair.second] = A[curPair.first][curPair.second] + 1;
                }
                else if (A[curPair.first + 1][curPair.second] == 1) return A[curPair.first][curPair.second] - 2;
            }
            if (curPair.second > 0) {
                if (A[curPair.first][curPair.second - 1] == 0) {
                    qu.push(pair<int, int>(curPair.first, curPair.second - 1));
                    A[curPair.first][curPair.second - 1] = A[curPair.first][curPair.second] + 1;
                }
                else if (A[curPair.first][curPair.second - 1] == 1) return A[curPair.first][curPair.second] - 2;
            }
            if (curPair.second < cols - 1) {
                if (A[curPair.first][curPair.second + 1] == 0) {
                    qu.push(pair<int, int>(curPair.first, curPair.second + 1));
                    A[curPair.first][curPair.second + 1] = A[curPair.first][curPair.second] + 1;
                }
                else if (A[curPair.first][curPair.second + 1] == 1) return A[curPair.first][curPair.second] - 2;
            }
        }
        return 1;
    }

    void search(vector<vector<int>>& A, int rows, int cols, int r, int c, queue<pair<int, int>>& qu) {
        qu.push(pair<int, int>(r, c));
        A[r][c] = 2;

        if (r > 0 && A[r - 1][c] == 1) search(A, rows, cols, r - 1, c, qu);
        if (r < rows - 1 && A[r + 1][c] == 1) search(A, rows, cols, r + 1, c, qu);
        if (c > 0 && A[r][c - 1] == 1) search(A, rows, cols, r, c - 1, qu);
        if (c < cols - 1 && A[r][c + 1] == 1) search(A, rows, cols, r, c + 1, qu); 
    }
};
