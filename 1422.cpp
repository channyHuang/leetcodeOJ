class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') count++;
        }
        int res = 0;
        int left = 0;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == '0') left++;
            else count--;
            res = max(res, left + count);
        }
        return res;
    }
};
