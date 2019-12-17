class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        int count[26] = {0};
        int minc = len;
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            if (minc > count[i]) minc = count[i];
        }
        for (int i = minc; i > 1; i--) {
            if (len % i != 0) continue;
            string str = s.substr(0, len / i);
            int j = 0, pos = 0;
            for (j = len / i; j < len; j++) {
                if (s[j] != str[pos]) break;
                pos++;
                if (pos >= len / i) pos = 0;
            }
            if (j >= len) return true;
        }
        return false;
    }
};
