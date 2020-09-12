class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '?') continue;
            char c = 'a';
            if (i > 0 && s[i - 1] == c) c++;
            if (i < s.length() - 1 && s[i + 1] == c) c++;
            if (i > 0 && s[i - 1] == c) c++;
            s[i] = c;
        }
        return s;
    }
};
