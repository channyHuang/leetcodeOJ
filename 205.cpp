class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if (len <= 1) return true;
        int maps[256];
        bool used[256] = {0};
        for (int i = 0; i < 256; i++) maps[i] = 256;
        for (int i = 0; i < len; i++) {
            if (maps[(unsigned char)s[i]] == 256) {
                //if (s[i] == t[i]) continue;
                //else {
                    if (used[(unsigned char)t[i]]) return false;
                    maps[(unsigned char)s[i]] = t[i];
                    used[(unsigned char)t[i]] = true;
                //}
            } else {
                if (maps[(unsigned char)s[i]] == t[i]) continue;
                else return false;
            }
        }
        return true;
    }
};
