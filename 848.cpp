class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int len = shifts.size();
        shifts[len - 1] %= 26;
        for (int i = len - 1; i > 0; i--) {
            shifts[i - 1] += shifts[i];
            shifts[i - 1] %= 26;
        }
        for (int i = 0; i < len; i++) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return S;
    }
};
