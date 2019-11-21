class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int left = 0;
        char c[2] = {0};
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                if (left > 0) {
                    c[0] = S[i];
                    res = res + string(c);
                }
                left++;
            } else {
                left--;
                if (left > 0) {
                    c[0] = S[i];
                    res += string(c);
                }
            }
        }
        return res;
    }
};
