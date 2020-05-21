class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(sub, 0, sizeof(sub));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                rows[i] |= (1 << (board[i][j] - '1'));
                cols[j] |= (1 << (board[i][j] - '1'));
                sub[i / 3 * 3 + j / 3] |= (1 << (board[i][j] - '1'));
            }
        }
        flag = false;
        search(board, 0, 0);
        return;
    }

    void search(vector<vector<char>>& board, int r, int c) {
        int nr = r; 
        int nc = c + 1;
        if (nc >= 9) {
            nc = 0;
            nr++;
        }
        
        if (board[r][c] != '.') {
            if (nr >= 9) {
                //result
                flag = true;
                return;
            }
            search(board, nr, nc);
            return;
        }
        for (int i = 0; i < 9; i++) {
            if ((rows[r] & (1 << i)) != 0) continue;
            if ((cols[c] & (1 << i)) != 0) continue;
            if ((sub[r / 3 * 3 + c / 3] & (1 << i)) != 0) continue;
            board[r][c] = i + '1';
            if (nr >= 9) {
                //result
                flag = true;
                return;
            }
            rows[r] |= (1 << i);
            cols[c] |= (1 << i);
            sub[r / 3 * 3 + c / 3] |= (1 << i);
            search(board, nr, nc);
            if (flag) return;
            rows[r] ^= (1 << i);
            cols[c] ^= (1 << i);
            sub[r / 3 * 3 + c / 3] ^= (1 << i);
            board[r][c] = '.';
        }
    }

private:
    bool flag;
    int rows[10], cols[10], sub[10];
};
