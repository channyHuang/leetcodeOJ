class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int res = 0;
        int stPos = 0;
        int endPos = 2;
        int count[3] = {0};
        count[s[0] - 'a']++;
        count[s[1] - 'a']++;
        count[s[2] - 'a']++;
        while (endPos < len) {
            if (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                    count[s[stPos] - 'a']--;
                    stPos++;                
                }
                res += stPos;// + len - endPos);
                stPos--;
                count[s[stPos] - 'a']++;
            }
            endPos++;
            if (endPos >= len) break;
            count[s[endPos] - 'a']++;
        }
        return res;
    }
};
