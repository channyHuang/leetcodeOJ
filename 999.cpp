class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rows = board.size();
		int res = 0;
		if (rows <= 0) return 0;
		int cols = board[0].size();
		if (cols <= 0) return 0;
		register int i, j;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				if (board[i][j] == 'R') break;
			}
			if (j < cols && board[i][j] == 'R') break;
		}
		int r = i, c = j;
		i = r - 1;
        j = c - 1;
		if (r >= rows || c >= cols) return 0;
		while (i >= 0) {
			if (board[i][c] == 'p') {
				res++;
				break;
			} else if (board[i][c] != '.') break;
			--i;
		}
		while (j >= 0) {
			if (board[r][j] == 'p') {
				res++;
				break;
			} else if (board[r][j] != '.') break;
			--j;
		}
		i = r + 1;
		while (i < rows) {
			if (board[i][c] == 'p') {
				res++;
				break;
			} else if (board[i][c] != '.') break;
			++i;
		}
		j = c + 1;
		while (j < cols) {
			if (board[r][j] == 'p') {
				res++;
				break;
			} else if (board[r][j] != '.') break;
			++j;
		}
		return res;
    }
};
