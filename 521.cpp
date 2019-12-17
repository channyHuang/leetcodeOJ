class Solution {
public:
    int findLUSlength(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        if (a != b) return lena > lenb ? lena : lenb;
        return -1;
    }
};
