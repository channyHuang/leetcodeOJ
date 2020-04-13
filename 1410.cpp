class Solution {
public:
    string entityParser(string text) {
        string res = text;
        int len = text.length();
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (text[i] != '&' || i >= len - 3) {
                res[pos++] = text[i];
                continue;
            }
            if (text[i + 2] == 't' && text[i + 3] == ';') {
                if (text[i + 1] == 'g') {
                    res[pos++] = '>';
                    i += 3;
                } else if (text[i + 1] == 'l') {
                    res[pos++] = '<';
                    i += 3;
                }
                else res[pos++] = text[i];
                continue;
            }
            if (i >= len - 4) {
                res[pos++] = text[i];
                continue;
            }
            if (text[i + 4] == ';') {
                if (text[i + 1] == 'a' && text[i + 2] == 'm' && text[i + 3] == 'p') {
                    res[pos++] = '&';
                    i += 4;
                } else res[pos++] = text[i];
                continue;
            }
            if (i >= len - 5) {
                res[pos++] = text[i];
                continue;
            }
            if (text[i + 5] == ';' && text[i + 3] == 'o') {
                if (text[i + 1] == 'q' && text[i + 2] == 'u' && text[i + 4] == 't') {
                    res[pos++] = '"';
                    i += 5;
                } else if (text[i + 1] == 'a' && text[i + 2] == 'p' && text[i + 4] == 's') {
                    res[pos++] = '\'';
                    i += 5;
                } else res[pos++] = text[i];
                continue;
            }
            if (i >= len - 6) {
                res[pos++] = text[i];
                continue;
            }
            if (text[i + 6] == ';' && text[i + 1] == 'f' && text[i + 2] == 'r' && text[i + 3] == 'a' && text[i + 4] == 's' && text[i + 5] == 'l') {
                res[pos++] = '/';
                i += 6;
            } else res[pos++] = text[i];
        }
        return res.substr(0, pos);
    }
};
