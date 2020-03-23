class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        int rows = queens.size();
        if (rows <= 0) return res;
        int cols = queens[0].size();
        if (cols <= 0) return res;
        int dif = king[1] - king[0];
        int sum = king[1] + king[0];
        int row[2] = {-1, 8};
        int col[2] = {-1, 8};
        int virrow[2] = {-1, 8};
        int vircol[2] = {-1, 8};
        for (int i = 0; i < rows; i++) {
            if (queens[i][0] == king[0]) {
                if (queens[i][1] < king[1]) {
                    col[0] = max(col[0], queens[i][1]);
                } else {
                    col[1] = min(col[1], queens[i][1]);
                }
            }
            if (queens[i][1] == king[1]) {
                if (queens[i][0] < king[0]) {
                    row[0] = max(row[0], queens[i][0]);
                } else {
                    row[1] = min(row[1], queens[i][0]);
                }
            }
            if (queens[i][1] - queens[i][0] == dif) {
                if (queens[i][0] < king[0]) {
                    virrow[0] = max(virrow[0], queens[i][0]);
                } else {
                    virrow[1] = min(virrow[1], queens[i][0]);
                }
            }
            if (queens[i][0] + queens[i][1] == sum) {
                if (queens[i][1] < king[1]) {
                    vircol[0] = max(vircol[0], queens[i][1]);
                } else {
                    vircol[1] = min(vircol[1], queens[i][1]);
                }
            }
        }
        if (row[0] != -1) {
            vector<int> subres;
            subres.push_back(row[0]);
            subres.push_back(king[1]);
            res.push_back(subres);
        }
        if (row[1] != 8) {
            vector<int> subres;
            subres.push_back(row[1]);
            subres.push_back(king[1]);
            res.push_back(subres);
        }
        if (col[0] != -1) {
            vector<int> subres;
            subres.push_back(king[0]);
            subres.push_back(col[0]);
            res.push_back(subres);
        }
        if (col[1] != 8) {
            vector<int> subres;
            subres.push_back(king[0]);
            subres.push_back(col[1]);
            res.push_back(subres);
        }
        if (virrow[0] != -1) {
            vector<int> subres;
            subres.push_back(virrow[0]);
            subres.push_back(virrow[0] + dif);
            res.push_back(subres);
        }
        if (virrow[1] != 8) {
            vector<int> subres;
            subres.push_back(virrow[1]);
            subres.push_back(virrow[1] + dif);
            res.push_back(subres);
        }
        if (vircol[0] != -1) {
            vector<int> subres;
            subres.push_back(sum - vircol[0]);
            subres.push_back(vircol[0]);
            res.push_back(subres);
        }
        if (vircol[1] != 8) {
            vector<int> subres;
            subres.push_back(sum - vircol[1]);
            subres.push_back(vircol[1]);
            res.push_back(subres);
        }
        return res;
    }
};
