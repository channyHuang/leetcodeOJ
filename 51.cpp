class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> left(n * 2, false);
        vector<bool> right(n * 2, false);
        nsize = n;
        vector<string> sub;
        {
            for (int i = 0; i < n; i++) {
                string s = "";
                s.resize(n, '.');
                sub.push_back(s);
            }
        }
        for (int i = 0; i < n; i++) {
            cols[i] = true;
            left[i] = true;
            right[i + n] = true;
            sub[0][i] = 'Q';
            search(sub, 1, cols, left, right);
            sub[0][i] = '.';
            left[i] = false;
            right[i + n] = false;
            cols[i] = false;
        }
        return res;
    }

    void search(vector<string>& sub, int r, vector<bool>& cols, vector<bool>& left, vector<bool>& right) {
        if (r >= nsize) {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < nsize; i++) {
            if (cols[i]) continue;
            if (left[i + r]) continue;
            if (right[i - r + nsize]) continue;
            cols[i] = true;
            left[i + r] = true;
            right[i - r + nsize] = true;
            sub[r][i] = 'Q';
            search(sub, r + 1, cols, left, right);
            sub[r][i] = '.';
            cols[i] = false;
            left[i + r] = false;
            right[i - r + nsize] = false;
        }
    }

private:
    vector<vector<string>> res;
    int nsize;
};
