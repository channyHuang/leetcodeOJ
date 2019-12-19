class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos;
        vector<int> res;
        res.resize(2);
        pos.resize(3);
        pos[0] = a;
        pos[1] = b;
        pos[2] = c;
        sort(pos.begin(), pos.end());
        if (pos[1] - pos[0] == 1) {
            res[0] = (pos[2] - pos[1] == 1 ? 0 : 1);
            res[1] = pos[2] - pos[1] - 1;
        } else if (pos[2] - pos[1] == 1) {
            res[0] = (pos[1] - pos[0] == 1 ? 0 : 1);
            res[1] = pos[1] - pos[0] - 1;
        } else if (pos[1] - pos[0] == 2 || pos[2] - pos[1] == 2) {
            res[0] = 1;
            res[1] = pos[2] - pos[1] - 1 + pos[1] - pos[0] - 1;
        }
        else {
            res[0] = 2;
            res[1] = pos[2] - pos[1] - 1 + pos[1] - pos[0] - 1;
        }
        return res;
    }
};
