class Solution {
public:
    string freqAlphabets(string s) {
        int len = s.length();
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (i + 2 >= len) {
                s[pos++] = s[i] - '1' + 'a';
            } else if (s[i + 2] == '#') {
                s[pos++] = (s[i] - '1') * 10 + (s[i + 1] - '0') + 'j';
                i += 2;
            } else {
                s[pos++] = s[i] - '1' + 'a';
            }
        }
        s[pos] = 0;
        return s;
    }
};