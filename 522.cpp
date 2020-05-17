class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int len = strs.size();
        if (len <= 0) return -1;
        if (len == 1) return strs[0].length();
        sort(strs.begin(), strs.end(), cmp);

        for (int i = 0, j = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                if (i == j) continue;
                if (strs[j].length() < strs[i].length()) return strs[i].length();
                if (isSub(strs[i], strs[j])) break;
            }
            if (j == len) return strs[i].length();
        }
        return -1;
    }

    static bool cmp(string &a, string &b) {
        if (a.length() == b.length()) return a < b;
        return a.length() > b.length();
    }

    bool isSub(string a, string b) {
        int lena = a.length(), lenb = b.length();
        int pos = 0, i = 0;
        for (i = 0; i < lena; i++) {
            while (pos < lenb && b[pos] != a[i]) pos++;
            if (pos >= lenb) break;
            pos++;
        }
        if (i >= lena) return true;
        return false;
    }
};
