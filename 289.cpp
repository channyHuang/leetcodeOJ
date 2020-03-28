class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows <= 0) return;
        int cols = board[0].size();
        if (cols <= 0) return;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int count = calc(board, rows, cols, i, j);
                if (board[i][j] == 0 && count == 3) board[i][j] = -1;
                else if (board[i][j] == 1) {
                    if (count < 2 || count > 3) board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }

    int calc(vector<vector<int>>& board, int rows, int cols, int r, int c) {
        int res = 0;
        if (board[r][c] == 0) {
            if (r > 0) {
                if (board[r - 1][c] > board[r][c]) res++;
                if (c > 0 && board[r - 1][c - 1] > board[r][c]) res++;
                if (c < cols - 1 && board[r - 1][c + 1] > board[r][c]) res++; 
            }
            if (r < rows - 1) {
                if (board[r + 1][c] > board[r][c]) res++;
                if (c > 0 && board[r + 1][c - 1] > board[r][c]) res++;
                if (c < cols - 1 && board[r + 1][c + 1] > board[r][c]) res++; 
            }
            if (c > 0 && board[r][c - 1] > board[r][c]) res++;
            if (c < cols - 1 && board[r][c + 1] > board[r][c]) res++;
        } else {
            if (r > 0) {
                if (board[r - 1][c] >= board[r][c]) res++;
                if (c > 0 && board[r - 1][c - 1] >= board[r][c]) res++;
                if (c < cols - 1 && board[r - 1][c + 1] >= board[r][c]) res++; 
            }
            if (r < rows - 1) {
                if (board[r + 1][c] >= board[r][c]) res++;
                if (c > 0 && board[r + 1][c - 1] >= board[r][c]) res++;
                if (c < cols - 1 && board[r + 1][c + 1] >= board[r][c]) res++; 
            }
            if (c > 0 && board[r][c - 1] >= board[r][c]) res++;
            if (c < cols - 1 && board[r][c + 1] >= board[r][c]) res++;
        }
        return res;
    }
};
