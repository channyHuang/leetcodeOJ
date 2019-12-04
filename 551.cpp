class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length();
        int countA = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'A') {
                countA++;
                if (countA >= 2) return false;
            } else if (s[i] == 'L') {
                if (i > 1 && s[i - 1] == 'L' && s[i - 2] == 'L') return false;
            }
        }
        return true;
    }
};
