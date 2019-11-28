class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        int res = 0;
        bool flag = false;
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') flag = true;
            else {
                if (flag) res++;
                flag = false;
            }
        }
        if (flag) res++;
        return res;
    }
};
