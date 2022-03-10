class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();
        int i, j;
        string res = "Draw";
        bool bpending = false;
        //diag
        bool bvalid = true;
        if (board[0][0] == ' ') {
            bpending = true;
        } else {
            for (i = 1; i < n; ++i) {
                if (board[i][i] == ' ') {
                    bpending = true;
                    bvalid = false;
                    break;
                } 
                if (board[i][i] != board[0][0]) {
                    bvalid = false;
                    if (bpending) break;
                }
            }
            if (bvalid) return board[0].substr(0, 1);
        }

        bvalid = true;
        if (board[0][n - 1] == ' ') {
            bpending = true;
        } else {
            for (i = 1; i < n; ++i) {
                if (board[i][n - i - 1] == ' ') {
                    bpending = true;
                    bvalid = false;
                    break;
                } 
                if (board[i][n - i - 1] != board[0][n - 1]) {
                    bvalid = false;
                    if (bpending) break;
                }
            }
            if (bvalid) return board[0].substr(n - 1, 1);
        }
        //row
        for (i = 0; i < n; ++i) {
            if (board[i][0] == ' ') {
                bpending = true;
                continue;
            }
            bvalid = true;
            for (j = 1; j < n; ++j) {
                if (board[i][j] == ' ') {
                    bpending = true;
                    bvalid = false;
                    break;
                }
                if (board[i][j] != board[i][0]) {
                    bvalid = false;
                    if (bpending) break;
                }
            }
            if (bvalid) return board[i].substr(0, 1);
        }
        //col
        for (j = 0; j < n; ++j) {
            if (board[0][j] == ' ') {
                bpending = true;
                continue;
            }
            bvalid = true;
            for (i = 1; i < n; ++i) {
                if (board[i][j] == ' ') {
                    bpending = true;
                    bvalid = false;
                    break;
                }
                if (board[i][j] != board[0][j]) {
                    bvalid = false;
                    if (bpending) break;
                };
            }
            if (bvalid) return board[0].substr(j, 1);
        }
        return (bpending ? "Pending" : "Draw");
    }
};
