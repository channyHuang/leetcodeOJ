class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows <= 0) return 0;
        int cols = board[0].size();
        if (cols <= 0) return 0;
        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '.') continue;
                if (i == 0 && j == 0) res++;
                else if (i == 0) {
                    if (board[i][j - 1] == '.') res++;
                } else if (j == 0) {
                    if (board[i - 1][j] == '.') res++;
                } else {
                    if (board[i - 1][j] == '.' && board[i][j - 1] == '.') res++;
                }
            }
        }

        return res;
    }
};
