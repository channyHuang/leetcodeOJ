class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][10];
        int cols[9][10];
        int sub[9][10];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(sub, 0, sizeof(sub));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                rows[i][board[i][j] - '0']++;
                if (rows[i][board[i][j] - '0'] > 1) return false;
                cols[j][board[i][j] - '0']++;
                if (cols[j][board[i][j] - '0'] > 1) return false;
                int idx = i / 3 * 3 + j / 3;
                sub[idx][board[i][j] - '0']++;
                if (sub[idx][board[i][j] - '0'] > 1) return false;
            }
        }
        return true;
    }
};
