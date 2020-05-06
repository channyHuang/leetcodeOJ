class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        int len = queries.size();
        int count[26];
        for (int i = 0; i < len; i++) {            
            memset(count, 0, sizeof(count));
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                count[s[j] - 'a']++;
            }
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (count[i] & 1) {
                    cnt++;
                }
            }
            if (queries[i][2] * 2 < cnt - 1) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};
