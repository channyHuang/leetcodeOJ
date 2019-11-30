class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.length();
        int left = 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'L') left++;
            else left--;
            if (left == 0) res++;
        }
        return res;
    }
};
