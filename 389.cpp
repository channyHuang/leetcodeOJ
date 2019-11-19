class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[30] = {0};
        int len = 0;
        while (s[len] != '\0') {
            count[s[len] - 'a']++;
            len++;
        }    
        len = 0;
        while (t[len] != '\0') {
            if (count[t[len] - 'a'] <= 0) return t[len];
            count[t[len] - 'a']--;
            len++;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return char(i + 'a');
        }
        return 0;
    }
};
