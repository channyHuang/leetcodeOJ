class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int rows = board.size();
        int cols = board[0].size();
        search(board, rows, cols, click[0], click[1]);
        return board;
    }

    void search(vector<vector<char>>& board, int& rows, int& cols, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        if (board[r][c] == 'M' || board[r][c] == 'B' || (board[r][c] >= '1' && board[r][c] <= '8')) return;
        int count = 0;
        if (r > 0) {
            if (board[r - 1][c] == 'M') count++;
            if (c > 0 && board[r - 1][c - 1] == 'M') count++;
            if (c < cols - 1 && board[r - 1][c + 1] == 'M') count++;
        }
        if (r < rows - 1) {
            if (board[r + 1][c] == 'M') count++;
            if (c > 0 && board[r + 1][c - 1] == 'M') count++;
            if (c < cols - 1 && board[r + 1][c + 1] == 'M') count++;
        }
        if (c > 0 && board[r][c - 1] == 'M') count++;
        if (c < cols - 1 && board[r][c + 1] == 'M') count++;
        if (count > 0) {
            board[r][c] = count + '0';
            return;
        }
        board[r][c] = 'B';
        search(board, rows, cols, r - 1, c - 1);
        search(board, rows, cols, r - 1, c);
        search(board, rows, cols, r - 1, c + 1);
        search(board, rows, cols, r, c - 1);
        search(board, rows, cols, r, c + 1);
        search(board, rows, cols, r + 1, c - 1);
        search(board, rows, cols, r + 1, c);
        search(board, rows, cols, r + 1, c + 1);
    }
};
