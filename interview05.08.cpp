class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);
        int col = w / 32;
        int row = length / col;
        int stidx = (y * col);
        int stpos = x1 / 32 + stidx;
        int stleft = 32 - x1 % 32;
        int endpos = x2 / 32 + stidx;
        int endleft = 31 - x2 % 32;

        if (stleft == 32) {
            res[stpos] = (~0);
        } else {
            res[stpos] |= ((1 << stleft) - 1);
        }
        for (int i = stpos + 1; i <= endpos; ++i) {
            res[i] = (~0);
        }
        if (endleft > 0) {
            res[endpos] ^= ((1 << endleft) - 1);
        }
        return res;
    }
};
