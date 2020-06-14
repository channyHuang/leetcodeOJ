class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if (!range(s1, s2)) return false;
        if (len <= 2) return true;
        for (int i = 1; i < len; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) 
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) return true;
        }
        return false;
    }

    bool range(string s1, string s2) {
        int len = s1.length();
        int count[256] = {0};
        for (int i = 0; i < len; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};
