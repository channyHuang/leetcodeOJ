class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> res;
        if (len <= 0) return res;
        int count[len][26] = {0};
        int reslen = 0;
        for (int i = 0; i < len; i++) {
            int strlen = strs[i].length();
            int j = 0;
            for (; j < 26; j++) {
                count[reslen][j] = 0;
            }
            j = 0;
            for (; j < strlen; j++) {
                count[reslen][strs[i][j] - 'a']++;
            }
            j = 0;
            for (; j < reslen; j++) {
                int k = 0;
                for (; k < 26; k++) {
                    if (count[reslen][k] != count[j][k]) break;
                }
                if (k == 26) {
                    res[j].push_back(strs[i]);
                    break;
                }
            }
            if (j == reslen) {
                vector<string> subres;
                subres.push_back(strs[i]);
                res.push_back(subres);
                reslen++;
            }
        }
        return res;
    }
};