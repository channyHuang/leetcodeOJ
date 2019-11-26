class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        int count[26] = {0};
        for (int i = 0; i < len; i++) {
            if (count[s[i] - 'a'] == 0) count[s[i] - 'a'] = i + 1;
            else count[s[i] - 'a'] = -1;
        }
        int res = -1;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0 && count[i] != -1) {
                if (res == -1) res = count[i] - 1;
                else res = (res < count[i] - 1 ? res : count[i] - 1);
            }
        }
        return res;
    }
};
