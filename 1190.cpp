class Solution {
public:
    string reverseParentheses(string s) {
        if (s.length() <= 0) return "";
        string::size_type pos = s.find_last_of("(");
        while (pos != string::npos) {
            string::size_type endPos = s.find_first_of(")", pos);
            s[pos] = ' ';
            s[endPos] = ' ';
            while (pos < endPos) {
                char tmp = s[pos];
                s[pos] = s[endPos];
                s[endPos] = tmp;
                pos++;
                endPos--;
            }
            pos = s.find_last_of("(");
        }
        pos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            s[pos++] = s[i];
        }
        s[pos] = 0;
        return s;
    }
};
