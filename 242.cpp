class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[256] = {0};
        int lens = s.length(), lent = t.length();
        if (lens != lent) return false;
        for (int i = 0; i < lens; i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};
