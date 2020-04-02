class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        int dir = 0; //right 0, down 1, left 2, up 3
        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0}; 
        int curRow = r0, curCol = c0;
        {
            vector<int> subres;
            subres.push_back(r0);
            subres.push_back(c0);
            res.push_back(subres);
        }
        int step = 1;
        while (1) {
            for (int i = 0; i < step; i++) {
                curRow += x[dir];
                curCol += y[dir];
                if (curRow >= 0 && curCol >= 0 && curRow < R && curCol < C) {
                    vector<int> subres;
                    subres.push_back(curRow);
                    subres.push_back(curCol);
                    res.push_back(subres);
                }
                if (res.size() >= R * C) break;
            }
            if (res.size() >= R * C) break;
            if (dir == 1 || dir == 3) step++;
            dir = (dir + 1) % 4;
        }

        return res;
    }
};
