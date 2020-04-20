class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int res[rows][cols];
        
        map<int, pair<int, int>> maps;
        map<int, pair<int, int>>::iterator itr;
        int curRow = rows - 1;
        int curCol = 0;
        bool right = true;
        for (int i = 1; i <= rows * cols; i++) {
            maps.insert(pair<int, pair<int, int>>(i, pair<int, int>(curRow, curCol)));
            res[curRow][curCol] = rows * cols + 1;
            if (right) {
                if (curCol < cols - 1) curCol++;
                else {
                    curRow--;
                    right = false;
                }
            } else {
                if (curCol > 0) curCol--;
                else {
                    curRow--;
                    right = true;
                }
            }
        }

        queue<int> qu;
        qu.push(1);
        res[rows - 1][0] = 0;
        while (!qu.empty()) {
            int curIdx = qu.front();
            itr = maps.find(curIdx);
            int r = itr->second.first;
            int c = itr->second.second;
            if (curIdx == rows * cols) return res[r][c];
            qu.pop();
            for (int i = 1; i < 7; i++) {
                //if (curIdx + i == rows * cols) return res[r][c] + 1;
                itr = maps.find(curIdx + i);
                if (itr == maps.end()) break;           
                int nr = itr->second.first;
                int nc = itr->second.second;
                if (board[nr][nc] == -1) {
                    if (res[nr][nc] > res[r][c] + 1) {
                        res[nr][nc] = res[r][c] + 1;
                        qu.push(curIdx + i);
                    }
                } else {
                    itr = maps.find(board[nr][nc]);
                    int nnr = itr->second.first;
                    int nnc = itr->second.second;
                    if (res[nnr][nnc] > res[r][c] + 1) {
                        res[nnr][nnc] = res[r][c] + 1;
                        qu.push(board[nr][nc]);
                    }
                }
            }
        }
        return -1;
    }
};
