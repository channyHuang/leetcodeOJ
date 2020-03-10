class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int count[2] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'O') count[1]++;
                else if (board[i][j] == 'X') count[0]++;
            }
        }
        if (count[1] > count[0] || count[1] < count[0] - 1) return false;
        bool flag[2] = {0};
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X') {
                    if (flag[1]) return false;
                    flag[0] = true;
                } else {
                    if (flag[0]) return false;
                    flag[1] = true;
                }
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X') {
                    if (flag[1]) return false;
                    flag[0] = true;
                } else {
                    if (flag[0]) return false;
                    flag[1] = true;
                }
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') {
                if (flag[1]) return false;
                flag[0] = true;
            } else {
                if (flag[0]) return false;
                flag[1] = true;
            }
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') {
                if (flag[1]) return false;
                flag[0] = true;
            } else {
                if (flag[0]) return false;
                flag[1] = true;
            }
        }
        if (flag[0] && count[0] == count[1]) return false;
        if (flag[1] && count[0] == count[1] + 1) return false;
        return true;
    }
};
