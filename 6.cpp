class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<char> newrows[numRows];
        int pos = 0;
        bool add = true;
        for (int i = 0; i < s.length(); i++) {
            newrows[pos].push_back(s[i]);
            if (add) {
                pos++;
                if (pos >= numRows - 1) add = false;
            } else {
                pos--;
                if (pos <= 0) add = true;
            }
        }
        string res = s;
        pos = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < newrows[i].size(); j++) {
                res[pos++] = newrows[i][j];
            }
        }
        return res;
    }
};
