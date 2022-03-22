class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int slen = s.length();   
        int qlen = queries.size();
        vector<int> pans(slen + 1, 0);
        vector<int> nextIdx(slen, -1);
        vector<int> preIdx(slen, -1);
        for (int i = 0; i < slen; ++i) {
            pans[i + 1] = pans[i];
            if (s[i] == '*') {
                pans[i + 1]++;
                if (i > 0) preIdx[i] = preIdx[i - 1];
            }
            else {
                preIdx[i] = i;
            }

            if (s[slen - i - 1] == '*') {
                if (slen - i - 1 < slen - 1) nextIdx[slen - i - 1] = nextIdx[slen - i];
            } else {
                nextIdx[slen - i - 1] = slen - i - 1;
            }
        }
        vector<int> res(qlen, 0);
        for (int i = 0; i < qlen; ++i) {
            int stpos = nextIdx[queries[i][0]];
            int endpos = preIdx[queries[i][1]];
            if (stpos == -1 || endpos == -1 || stpos > endpos) continue;
            res[i] = pans[endpos] - pans[stpos];
        }
        return res;
    }
};
