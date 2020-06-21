class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        bool match[lens + 1][lenp + 1];
        memset(match, 0, sizeof(match));
        for (int i = 0; i <= lens; i++) {
            for (int j = 0; j <= lenp; j++) {
                if (i == 0 && j == 0) {
                    match[0][0] = true;
                } else if (j == 0) {
                    match[i][0] = false;
                } else if (i == 0) {
                    match[0][j] = (p[j - 1] == '*' && match[0][j - 1]);
                } else if (p[j - 1] == '?') {
                    match[i][j] = match[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    for (int y = i; y >= 0; y--) {
                        if (match[y][j - 1]) {
                            match[i][j] = true;
                            break;
                        }
                    }
                } else {
                    match[i][j] = (s[i - 1] == p[j - 1] && match[i - 1][j - 1]);
                }
            }
        }
        return match[lens][lenp];
    }

    bool subMatch(char *s, char *p) {
        if (!*p) return (!*s);
        if (!*s) return ((*p) == '*' && isMatch(s, p + 1));
        if (*p != '?' && *p != '*') return (*s == *p && isMatch(s + 1, p + 1));
        if (*p == '?') return (isMatch(s + 1, p + 1));
        return (isMatch(s, p + 1) || isMatch(s + 1, p));
    }
};


//TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        return subMatch(s.data(), p.data());
    }

    bool subMatch(char *s, char *p) {
        if (!*p) return (!*s);
        if (!*s) return ((*p) == '*' && isMatch(s, p + 1));
        if (*p != '?' && *p != '*') return (*s == *p && isMatch(s + 1, p + 1));
        if (*p == '?') return (isMatch(s + 1, p + 1));
        return (isMatch(s, p + 1) || isMatch(s + 1, p));
    }
};
