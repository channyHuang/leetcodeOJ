class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        int counta[26] = {0};
        int countb[26] = {0};
        bool hassame = false;
        int diff = 0;
        for (int i = 0; i < A.length(); i++) {
            counta[A[i] - 'a']++;
            countb[B[i] - 'a']++;
            if (counta[A[i] - 'a'] >= 2) hassame = true;
            if (A[i] != B[i]) diff++;
            if (diff > 2) return false;
        }
        if (diff != 2 && diff != 0) return false;
        if (diff == 0) return hassame;
        for (int i = 0; i < 26; i++) {
            if (counta[i] != countb[i]) return false;
        }
        return true;
    }
};
