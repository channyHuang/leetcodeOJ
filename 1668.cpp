class Solution {
public:
    int maxRepeating(string sequence, string word) {
        olen = sequence.length();
        res = 0;
        int wlen = word.length();
        string target = word;
        int tlen = wlen;

        for (int i = 0; i < olen; i++) {
            if (i + tlen > olen) break;
            if (!same(sequence, i, target)) continue;
            res++;
            target += word;
            tlen += wlen;
            i--;
        }
        return res;
    }

    bool same(string& origin, int stPos, string& target) {
        int tlen = target.length();
        if (stPos + tlen > olen) return false;
        for (int i = 0; i < tlen; i++) {
            if (origin[stPos + i] != target[i]) return false;
        }
        return true;
    }

private:
    int olen;
    int res;
};
