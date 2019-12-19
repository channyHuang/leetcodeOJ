class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        bool used[R + 1][C + 1];
        memset(used, false, sizeof(used));
        vector<int> subres;
        subres.push_back(r0);
        subres.push_back(c0);
        res.push_back(subres);
        used[r0][c0] = true;
        int pos = 0;
        while (1) {
            int r = res[pos][0], c = res[pos][1];
            if ((r - 1 >= 0) && (!used[r - 1][c])) {
                vector<int> sub;
                sub.push_back(r - 1);
                sub.push_back(c);
                res.push_back(sub);
                used[r - 1][c] = true;
            } 
            if ((r + 1 < R) && (!used[r + 1][c])) {
                vector<int> sub;
                sub.push_back(r + 1);
                sub.push_back(c);
                res.push_back(sub);
                used[r + 1][c] = true;
            } 
            if ((c - 1 >= 0) && (!used[r][c - 1])) {
                vector<int> sub;
                sub.push_back(r);
                sub.push_back(c - 1);
                res.push_back(sub);
                used[r][c - 1] = true;
            }
            if ((c + 1 < C) && (!used[r][c + 1])) {
                vector<int> sub;
                sub.push_back(r);
                sub.push_back(c + 1);
                res.push_back(sub);
                used[r][c + 1] = true;
            }
            pos++;
            if (pos >= res.size()) break;
        }
        return res;
    }
};
