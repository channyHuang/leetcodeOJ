class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int mapStPos[26];
        for (int i = 0; i < 26; i++) mapStPos[i] = -1;
        int stPos = 0;
        int len = str.length();
        for (int i = 0; i < pattern.length(); i++) {
            if (stPos >= len) return false; 
            if (mapStPos[pattern[i] - 'a'] == -1) {
                mapStPos[pattern[i] - 'a'] = stPos;
                while (stPos < len && str[stPos] != ' ') stPos++;
                if (stPos >= len) continue;
                if (str[stPos] == ' ') stPos++;
            } else {
                int j = mapStPos[pattern[i] - 'a'];
                while (str[j] != ' ') {
                    if (str[j] != str[stPos]) return false;
                    j++;
                    stPos++;
                }
                if (stPos >= len) continue;
                if (str[stPos] != ' ') return false;
                stPos++;
            }
        }
        return stPos == len ? true : false;
    }
};
