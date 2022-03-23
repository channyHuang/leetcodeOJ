class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> scount(26, 0);
        vector<int> tcount(26, 0);
        for (int i = 0; i < s.length(); ++i) {
          scount[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); ++i) {
          tcount[t[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
          if (scount[i] == tcount[i]) continue;
          res += std::abs(scount[i] - tcount[i]);
        }
        return res;
    }
};
