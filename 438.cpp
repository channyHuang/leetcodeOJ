class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenp = p.length();
        int lens = s.length();
        vector<int> res;
        if (lens < lenp) return res;
        int count[26] = {0};
        for (int i = 0; i < lenp; i++) {
            count[p[i] - 'a']++;
        }
        int hashs = 0;
        int cnts[26] = {0};
        for (int i = 0; i < lenp; i++) {
            cnts[s[i] - 'a']++;
        }
        if (same(count, cnts)) res.push_back(0);
        for (int i = lenp; i < lens; i++) {
            cnts[s[i] - 'a']++;
            cnts[s[i - lenp] - 'a']--;
            if (same(count, cnts)) res.push_back(i - lenp + 1);
        }
        
        return res;
    }

    bool same(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
