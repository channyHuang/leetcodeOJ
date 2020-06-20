class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        string res = s;
        int pos = 0;
        int count[26] = {0};
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
        }
        bool used[26] = {false};
        for (int i = 0; i < len; i++) {
            if (pos == 0) {a
                res[pos++] = s[i];
                used[s[i] - 'a'] = true;
                continue;
            }
            if (used[s[i] - 'a']) {
                count[s[i] - 'a']--;
                continue;
            }
            if (count[res[pos - 1] - 'a'] > 1 && res[pos - 1] > s[i]) {
                count[res[pos - 1] - 'a']--;
                used[res[pos - 1] - 'a'] = false;
                pos--;
                i--;
                continue;
            }
            res[pos++] = s[i];
            used[s[i] - 'a'] = true;
        }
        res[pos] = 0;
        return res;
    }
};
