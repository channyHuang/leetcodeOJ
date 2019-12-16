class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int lens = 0, lent = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '#') {
                if (lens != 0) lens--;
            } else S[lens++] = S[i];
        }
        S[lens] = 0;
        for (int i = 0; i < T.length(); i++) {
            if (T[i] == '#') {
                if (lent != 0) lent--;
            } else T[lent++] = T[i]; 
        }
        T[lent] = 0;

        if (lens != lent) return false;
        for (int i = 0; i < lens; i++) {
            if (S[i] != T[i]) return false;
        }
        return true;
    }
};
