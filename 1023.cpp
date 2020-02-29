class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        int len = queries.size();
        res.resize(len);
        int plen = pattern.length();
        for (int i = 0; i < len; i++) {
            int j;
            int slen = queries[i].length();
            int pos = 0;
            for (j = 0; j < slen; j++) {
                if ((pos < plen) && (queries[i][j] == pattern[pos])) {
                    pos++;
                } else {
                    if (queries[i][j] > 'z' || queries[i][j] < 'a') {
                        break;
                    }
                }
            }
            if ((j == slen) && (pos == plen)) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};
