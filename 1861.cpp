class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();

        vector<vector<char>> res(col, vector<char>(row, '.'));
        for (int i = 0; i < row; ++i) {
            res[col - 1][row - i - 1] = box[i][col - 1];
            int pos = col - 1;
            for (int j = col - 2; j >= 0; --j) {
                if (box[i][j] == '.') continue;
                if (box[i][j] == '*') {
                    res[j][row - i - 1] = box[i][j];
                    pos = j;
                    continue;
                }
                if (res[pos][row - i - 1] == '.') {
                    res[pos][row - i - 1] = box[i][j];
                    pos--;
                    continue;
                }
                res[pos - 1][row - i - 1] = box[i][j];
                pos--;
            }
        }

        return res;
    }
};