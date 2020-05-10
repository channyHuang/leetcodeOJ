class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int len = s1.length();
        int i;
        for (i = 0; i < len; i++) {
            if (s1[i] > s2[i]) break;
        }
        if (i == len) return true;
        for (i = 0; i < len; i++) {
            if (s1[i] < s2[i]) break;
        }
        return i == len;
    }
};
