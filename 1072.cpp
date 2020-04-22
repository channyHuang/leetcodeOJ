class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        map<string, int> maps;
        map<string, int>::iterator itr;
        int res = 1;
        for (int i = 0; i < rows; i++) {
            string sub = "0";
            if (matrix[i][0] == 0) {
                for (int j = 1; j < cols; j++) sub += to_string(matrix[i][j]);
            } else {
                for (int j = 1; j < cols; j++) sub += to_string(1 - matrix[i][j]);
            }
            itr = maps.find(sub);
            if (itr == maps.end()) maps.insert(pair<string, int>(sub, 1));
            else {
                itr->second++;
                res = max(res, itr->second);
            }
        }
        return res;
    }
};
