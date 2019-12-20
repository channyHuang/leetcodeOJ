class Solution {
public:
    string toGoatLatin(string S) {
        int len = S.length();
        if (len <= 0) return "";
        string res;
        int residx = 0;
        res.resize(40000);
        int pos = 0;
        char pre;
        int count = 1;
        bool isaeiou = false;
        for (int i = 0; i <= len; i++) {
            if (S[i] == ' ' || S[i] == 0) {
                pos = i + 1;
                if (S[i - 1] == ' ') {
                    continue;
                }
                if (!isaeiou) res[residx++] = pre;
                
                res[residx++] = 'm';
                res[residx++] = 'a';
                for (int j = 0; j < count; j++) res[residx++] = 'a';
                count++;
                continue;
            }
            if (i == pos) {
                isaeiou = aeiou(S[i]);
                if (residx != 0) res[residx++] = ' ';
                if (isaeiou) res[residx++] = S[i];
                else pre = S[i];
                continue;
            }
            res[residx++] = S[i];
        }
        
        return res;
    }

    bool aeiou(char c) {
        if (c == 'a' || c == 'A') return true;
        if (c == 'e' || c == 'E') return true;
        if (c == 'i' || c == 'I') return true;
        if (c == 'o' || c == 'O') return true;
        if (c == 'u' || c == 'U') return true;
        return false;
    }
};
