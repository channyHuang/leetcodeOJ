class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (i == s.length()) {
                res = max(res, cnt);
                break;
            }
            if (s[i] == c) cnt++;
            else {
                res = max(res, cnt);
                c = s[i];
                cnt = 1;
            }
        }
        return res;
    }
};
