class Solution {
public:
    bool canConstruct(string s, int k) {
        int len = s.length();
        if (len < k) return false;
        if (len == k) return true;
        int count[26];
        memset(count, 0, sizeof(count));
        int odd = 0;
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] & 1) odd++;
            else odd--;
        }
        if (odd > k) return false;
        return true;
    }
};
