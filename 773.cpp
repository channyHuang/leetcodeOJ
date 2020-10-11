class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int next = mat2int(board);
        dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> qu;
        qu.push(pair<int, int>(next, 0));
        reach.insert(next);
        while (!qu.empty()) {
            pair<int, int> cur = qu.front();
            qu.pop();
            if (cur.first == 123450) return cur.second;
            vector<vector<int>> curmat = int2mat(cur.first);
            for (int i = 0; i < 4; i++) {
                if (move(curmat, i)) {
                    next = mat2int(curmat);
                    if (reach.find(next) == reach.end()) {
                        reach.insert(next);
                        qu.push(pair<int, int>(next, cur.second + 1));
                    }
                    move(curmat, (i + 2) % 4);
                }
            }
        }
        return -1;
    }

    int mat2int(vector<vector<int>>& board) {
        int res = 0;
        int cnt = 100000;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                res += (board[i][j] * cnt);
                cnt /= 10;
            }
        }
        return res;
    }

    vector<vector<int>> int2mat(int n) {
        vector<vector<int>> res(2, vector<int>(3, 0));
        int cnt = 100000;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                res[i][j] = (n / cnt % 10);
                cnt /= 10;
            }
        }
        return res;
    }

    bool move(vector<vector<int>>& board, int d) {
        int i = 0, j = 0;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 0) break;
            }
            if (j < 3 && board[i][j] == 0) break;
        }
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];
        if (ni < 0 || nj < 0 || ni >= 2 || nj >= 3) return false;
        int tmp = board[i][j];
        board[i][j] = board[ni][nj];
        board[ni][nj] = tmp;
        return true;
    }

private:
    vector<vector<int>> dir;
    unordered_set<int> reach;
};
