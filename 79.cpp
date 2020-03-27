class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        if (rows <= 0) return false;
        cols = board[0].size();
        if (cols <= 0) return false;
        int len = word.length();
        if (len <= 0) return true;
        bool used[205][205];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != word[0]) continue;
                used[i][j] = true;
                search(board, i, j, word, used, 1);
                used[i][j] = false;
            }
        }
        return flag;
    }

    void search(vector<vector<char>>& board, int stRow, int stCol, string word, bool used[205][205], int pos) {
        if (pos >= word.length()) {
            flag = true;
            return;
        }
        if (flag) return;
        if (stRow > 0) { //up
            if (!used[stRow - 1][stCol] && board[stRow - 1][stCol] == word[pos]) {
                used[stRow - 1][stCol] = true;
                search(board, stRow - 1, stCol, word, used, pos + 1);
                if (flag) return;
                used[stRow - 1][stCol] = false;
            }
        }
        if (stRow < rows - 1) {
            if (!used[stRow + 1][stCol] && board[stRow + 1][stCol] == word[pos]) {
                used[stRow + 1][stCol] = true;
                search(board, stRow + 1, stCol, word, used, pos + 1);
                if (flag) return;
                used[stRow + 1][stCol] = false;
            }
        }
        if (stCol > 0) {
            if (!used[stRow][stCol - 1] && board[stRow][stCol - 1] == word[pos]) {
                used[stRow][stCol - 1] = true;
                search(board, stRow, stCol - 1, word, used, pos + 1);
                if (flag) return;
                used[stRow][stCol - 1] = false;
            }
        }
        if (stCol < cols - 1) {
            if (!used[stRow][stCol + 1] && board[stRow][stCol + 1] == word[pos]) {
                used[stRow][stCol + 1] = true;
                search(board, stRow, stCol + 1, word, used, pos + 1);
                if (flag) return;
                used[stRow][stCol + 1] = false;
            }
        }
    }

private:
    bool flag;
    int rows;
    int cols;
};
