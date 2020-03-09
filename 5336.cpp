class Solution {
public:
    string sortString(string s) {
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        int pos = 0;
        string res = s;
        while (pos < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (count[i]) {
                    res[pos++] = i + 'a';
                    count[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (count[i]) {
                    res[pos++] = i + 'a';
                    count[i]--;
                }
            }
        }
        return res;
    }
};
