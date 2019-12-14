class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
        int len = S.length();
        int line = 0, left = 0;
        for (int i = 0; i < len; i++) {
            int tmp = left + widths[S[i] - 'a'];
            if (tmp == 100) {
                line++;
                left = 0;
            } else if (tmp > 100) {
                line++;
                left = widths[S[i] - 'a'];
            } else {
                left = tmp;
            }
        }
        if (left != 0) line++;
        res.push_back(line);
        res.push_back(left);
        return res;
    }
};
