class Solution {
public:
    int longestPalindrome(string s) {
        int count[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
        }
        int res = 0;
        bool even = true;
        for (int i = 0; i < 256; i++) {
            res += (count[i] / 2);
            if (even && (count[i] & 1)) even = false;
        }
        return res * 2 + (even ? 0 : 1);
    }
};
