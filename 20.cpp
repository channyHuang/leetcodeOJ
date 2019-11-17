class Solution {
public:
    bool isValid(string s) {
        char cs[s.length() + 1] = {0};
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                cs[len++] = s[i];
            } else {
                if (len == 0) return false;
                if (s[i] == ')' && cs[len-1] == '(') len--;
                else if (s[i] == ']' && cs[len-1] == '[') len--;
                else if (s[i] == '}' && cs[len-1] == '{') len--;
                else return false;
            }
        }
        if (len != 0) return false;
        return true;
    }
};
