class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> res(rows, vector<int>(cols, 0)); 
        vector<pair<int, int>> vecRows;
        for (int i = 0; i < rows; i++) {
            vecRows.push_back(pair<int, int>(rowSum[i], i));
        }
        vector<pair<int, int>> vecCols;
        for (int i = 0; i < cols; i++) {
            vecCols.push_back(pair<int, int>(colSum[i], i));
        }
        sort(vecRows.begin(), vecRows.end(), cmp);
        sort(vecCols.begin(), vecCols.end(), cmp);
        int rowPos = 0, colPos = 0;
        while (rowPos < rows && colPos < cols) {
            if (vecRows[rowPos].first <= vecCols[colPos].first) {
                res[vecRows[rowPos].second][vecCols[colPos].second] = vecRows[rowPos].first;
                vecCols[colPos].first -= vecRows[rowPos].first;
                rowPos++;
                if (vecCols[colPos].first <= 0) colPos++;
            } else {
                res[vecRows[rowPos].second][vecCols[colPos].second] = vecCols[colPos].first;
                vecRows[rowPos].first -= vecCols[colPos].first;
                colPos++;
                if (vecRows[rowPos].first <= 0) rowPos++;
            }
        }
        return res;
    }

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};
