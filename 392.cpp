class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tlen = t.length();
        int slen = s.length();
        int pos = 0;
        for (int i = 0; i < slen ;i++) {
            while (pos < tlen && s[i] != t[pos]) pos++;
            if (pos >= tlen) return false;
            pos++;
        }
        return true;
    }
};
