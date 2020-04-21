class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int len = colsum.size();
        vector<vector<int>> res;
        res.resize(2);
        for (int i = 0; i < len; i++) {
            if (colsum[i] == 0) {
                res[0].push_back(0);
                res[1].push_back(0);
            } else if (colsum[i] == 2) {
                if (upper <= 0 || lower <= 0) {
                    vector<vector<int>> sub;
                    return sub;
                }
                res[0].push_back(1);
                res[1].push_back(1);
                upper--;
                lower--;
            } else {
                if (upper == 0 && lower == 0) {
                    vector<vector<int>> sub;
                    return sub;
                }
                if (upper >= lower) {
                    res[0].push_back(1);
                    res[1].push_back(0);
                    upper--;
                } else {
                    res[0].push_back(0);
                    res[1].push_back(1);
                    lower--;
                }
            }
        }
        if (upper || lower) {
            vector<vector<int>> sub;
            return sub;
        }
        return res;
    }
};