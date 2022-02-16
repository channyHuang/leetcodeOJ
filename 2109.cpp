class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int slen = s.length();
        int len = spaces.size();
        string res(slen + len, ' ');
        int pos = 0, spos = 0;
        for (int i = 0; i < slen; ++i) {
            if (spos >= len) {
                res[pos++] = s[i];
                continue;
            }
            if (i == spaces[spos]) {
                pos++;
                spos++;
                res[pos++] = s[i];
                continue;
            }
            res[pos++] = s[i];
        }
        return res;
    }
};