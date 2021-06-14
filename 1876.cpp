class Solution {
public:
    int countGoodSubstrings(string s) {
        int len = s.length();
        int res = 0;
        set<string> sub;
        for (int i = 2; i < len; i++) {
            if (s[i] == s[i - 1] || s[i] == s[i - 2] || s[i - 1] == s[i - 2]) continue;
            //if (sub.find(s.substr(i - 2, 3)) != sub.end()) continue;
            sub.insert(s.substr(i - 2, 3));
            res++;
        }
        return res;
    }
};
