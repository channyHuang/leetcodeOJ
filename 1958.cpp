class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        row = board.size();
        col = board[0].size();

        return (up(board, rMove, cMove, color) 
              || down(board, rMove, cMove, color) 
              || left(board, rMove, cMove, color) 
              || right(board, rMove, cMove, color) 
              || leftdown(board, rMove, cMove, color) 
              || rightdown(board, rMove, cMove, color) 
              || leftup(board, rMove, cMove, color) 
              || rightup(board, rMove, cMove, color) 
        );
    }

    bool up(vector<vector<char>>& board, int r, int c, char color) {
        if (r <= 1) return false;
        char target = revertColor(color);
        if (board[r - 1][c] != target) return false;
        int i = 2;
        while (r - i > 0 && board[r - i][c] == target) i++;
        return (board[r - i][c] == color);
    }

    bool down(vector<vector<char>>& board, int r, int c, char color) {
        if (r >= row - 2) return false;
        char target = revertColor(color);
        if (board[r + 1][c] != target) return false;
        int i = 2;
        while (r + i < row - 1 && board[r + i][c] == target) i++;
        return (board[r + i][c] == color);
    }

    bool left(vector<vector<char>>& board, int r, int c, char color) {
        if (c <= 1) return false;
        char target = revertColor(color);
        if (board[r][c - 1] != target) return false;
        int i = 2;
        while (c - i > 0 && board[r][c - i] == target) i++;
        return (board[r][c - i] == color);
    }

    bool right(vector<vector<char>>& board, int r, int c, char color) {
        if (c >= col - 2) return false;
        char target = revertColor(color);
        if (board[r][c + 1] != target) return false;
        int i = 2;
        while (c + i < col - 1 && board[r][c + i] == target) i++;
        return (board[r][c + i] == color);
    }

    bool leftup(vector<vector<char>>& board, int r, int c, char color) {
        if (c <= 1 || r <= 1) return false;
        char target = revertColor(color);
        if (board[r - 1][c - 1] != target) return false;
        int i = 2;
        while (c - i > 0 && r - i > 0 && board[r - i][c - i] == target) i++;
        return (board[r - i][c - i] == color);
    }

    bool rightdown(vector<vector<char>>& board, int r, int c, char color) {
        if (c >= col - 2 || r >= row - 2) return false;
        char target = revertColor(color);
        if (board[r + 1][c + 1] != target) return false;
        int i = 2;
        while (c + i < col - 1 && r + i < row - 1 && board[r + i][c + i] == target) i++;
        return (board[r + i][c + i] == color);
    }

    bool rightup(vector<vector<char>>& board, int r, int c, char color) {
        if (c >= col - 2 || r <= 1) return false;
        char target = revertColor(color);
        if (board[r - 1][c + 1] != target) return false;
        int i = 2;
        while (c + i < col - 1 && r - i > 0 && board[r - i][c + i] == target) i++;
        return (board[r - i][c + i] == color);
    }

    bool leftdown(vector<vector<char>>& board, int r, int c, char color) {
        if (c <= 1 || r >= row - 2) return false;
        char target = revertColor(color);
        if (board[r + 1][c - 1] != target) return false;
        int i = 2;
        while (c - i > 0 && r + i < row - 1 && board[r + i][c - i] == target) i++;
        return (board[r + i][c - i] == color);
    }

    char revertColor(char color) {
        if (color == 'B') return 'W';
        else return 'B';
    }

private:
    int row, col;
};
