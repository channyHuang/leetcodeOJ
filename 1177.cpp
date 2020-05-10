class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int len = queries.size();
        vector<bool> res(len, false);
        int bits[s.length()];
        bits[0] = (1 << (s[0] - 'a'));
        for (int i = 1; i < s.length(); i++) {
            bits[i] = (bits[i - 1] ^ (1 << (s[i] - 'a')));
        }
        for (int i = 0; i < len; i++) {
            int num;
            if (queries[i][0] == 0) num = (bits[queries[i][1]]);
            else num = (bits[queries[i][1]] ^ bits[queries[i][0] - 1]);
            int cnt = 0;
            while (num) {
                cnt++;
                num &= (num - 1);
            }
            int clen = queries[i][1] - queries[i][0] + 1;
            if ((clen & 1) == 0 && cnt <= queries[i][2] * 2) res[i] = true;
            else if ((clen & 1) == 1 && cnt - 1 <= queries[i][2] * 2) res[i] = true;
        }
        return res;
    }
};
