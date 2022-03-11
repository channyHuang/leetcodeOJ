class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        row = chessboard.size();
        col = chessboard[0].length();
        res = 0;
        vector<string> curchess(row);
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (chessboard[i][j] != '.') continue;
				for (int l = 0; l < row; ++l) {
					curchess[l] = chessboard[l];
				}
                
                curchess[i][j] = 'X';
                int tmp = search(curchess, i, j);
				if (res < tmp) {
					res = tmp;
				}
            }
        }
        return res;
    }

    int search(vector<string>& chessboard, int r, int c) {
        int res = 0, endpos;
        queue<pair<int, int>> qu;
        if (r - 1 > 0 && chessboard[r - 1][c] == 'O') {
			endpos = 2;
            while (r - endpos > 0 && chessboard[r - endpos][c] == 'O') endpos++;
            if (chessboard[r - endpos][c] == 'X') {
                for (int i = 1; i < endpos; ++i) {
                    qu.push(make_pair(r - i, c));
                    chessboard[r - i][c] = 'X';
                }
                res += (endpos - 1);
            }
        }
        if (r + 1 < row - 1 && chessboard[r + 1][c] == 'O') {
            endpos = 2;
            while (r + endpos < row - 1 && chessboard[r + endpos][c] == 'O') endpos++;
            if (chessboard[r + endpos][c] == 'X') {
                for (int i = 1; i < endpos; ++i) {
                    qu.push(make_pair(r + i, c));
                    chessboard[r + i][c] = 'X';
                }
                res += (endpos - 1);
            }
        }
		if (c - 1 > 0 && chessboard[r][c - 1] == 'O') {
			endpos = 2;
			while (c - endpos > 0 && chessboard[r][c - endpos] == 'O') endpos++;
			if (chessboard[r][c - endpos] == 'X') {
				for (int i = 1; i < endpos; ++i) {
					qu.push(make_pair(r, c - i));
					chessboard[r][c - i] = 'X';
				}
				res += (endpos - 1);
			}
		}
		if (c + 1 < col - 1 && chessboard[r][c + 1] == 'O') {
			endpos = 2;
			while (c + endpos < col - 1 && chessboard[r][c + endpos] == 'O') endpos++;
			if (chessboard[r][c + endpos] == 'X') {
				for (int i = 1; i < endpos; ++i) {
					qu.push(make_pair(r, c + i));
					chessboard[r][c + i] = 'X';
				}
				res += (endpos - 1);
			}
		}
        if (r - 1 > 0 && c - 1 > 0 && chessboard[r - 1][c - 1] == 'O') {
            endpos = 2;
            while (r - endpos > 0 && c - endpos > 0 && chessboard[r - endpos][c - endpos] == 'O') endpos++;
            if (chessboard[r - endpos][c - endpos] == 'X') {
                for (int i = 1; i < endpos; ++i) {
                    qu.push(make_pair(r - i, c - i));
                    chessboard[r - i][c - i] = 'X';
                }
                res += (endpos - 1);
            }
        }
		if (r + 1 < row - 1 && c + 1 < col - 1 && chessboard[r + 1][c + 1] == 'O') {
			endpos = 2;
			while (r + endpos < row - 1 && c + endpos < col - 1 && chessboard[r + endpos][c + endpos] == 'O') endpos++;
			if (chessboard[r + endpos][c + endpos] == 'X') {
				for (int i = 1; i < endpos; ++i) {
					qu.push(make_pair(r + i, c + i));
					chessboard[r + i][c + i] = 'X';
				}
				res += (endpos - 1);
			}
		}
		if (r - 1 > 0 && c + 1 < col - 1 && chessboard[r - 1][c + 1] == 'O') {
			endpos = 2;
			while (r - endpos > 0 && c + endpos < col - 1 && chessboard[r - endpos][c + endpos] == 'O') endpos++;
			if (chessboard[r - endpos][c + endpos] == 'X') {
				for (int i = 1; i < endpos; ++i) {
					qu.push(make_pair(r - i, c + i));
					chessboard[r - i][c + i] = 'X';
				}
				res += (endpos - 1);
			}
		}
		if (r + 1 < row - 1 && c - 1 > 0 && chessboard[r + 1][c - 1] == 'O') {
			endpos = 2;
			while (r + endpos < row - 1 && c - endpos > 0 && chessboard[r + endpos][c - endpos] == 'O') endpos++;
			if (chessboard[r + endpos][c - endpos] == 'X') {
				for (int i = 1; i < endpos; ++i) {
					qu.push(make_pair(r + i, c - i));
					chessboard[r + i][c - i] = 'X';
				}
				res += (endpos - 1);
			}
		}
		while (!qu.empty()) {
			auto cur = qu.front();
			qu.pop();
			res += search(chessboard, cur.first, cur.second);
		}
		return res;
    }

private:
    int row, col;
    int res = 0;
};
