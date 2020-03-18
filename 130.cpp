class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows <= 0) return;
        int cols = board[0].size();
        if (cols <= 0) return;
        vector<vector<bool>> keep;
        for (int i = 0; i < rows; i++) {
            vector<bool> subkeep;
            subkeep.resize(cols);
            keep.push_back(subkeep);
        }
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O' && keep[i][0] == false) search(keep, board, rows, cols, i, 0);
            if (board[i][cols - 1] == 'O' && keep[i][cols - 1] == false) search(keep, board, rows, cols, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O' && keep[0][j] == false) search(keep, board, rows, cols, 0, j);
            if (board[rows - 1][j] == 'O' && keep[rows - 1][j] == false) search(keep, board, rows, cols, rows - 1, j);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && !keep[i][j]) board[i][j] = 'X';
            }
        }
        return;
    }

    void search(vector<vector<bool>>& keep, vector<vector<char>>& board, int rows, int cols, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        if (board[r][c] == 'X') return;
        if (keep[r][c]) return;
        keep[r][c] = true;
        search(keep, board, rows, cols, r - 1, c);
        search(keep, board, rows, cols, r + 1, c);
        search(keep, board, rows, cols, r, c - 1);
        search(keep, board, rows, cols, r, c + 1);
    }
};
