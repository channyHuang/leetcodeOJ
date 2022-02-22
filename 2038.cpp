class Solution {
public:
    bool winnerOfGame(string colors) {
        int len = colors.length();
        if (len <= 2) return false;
        int counta = 0, countb = 0;
        for (int i = 1; i < len - 1; ++i) {
            if (colors[i] == 'A') {
                if (colors[i - 1] == 'A' && colors[i + 1] == 'A') counta++;
            } else {
                if (colors[i - 1] == 'B' && colors[i + 1] == 'B') countb++;
            }
        }
        return (counta > countb);
    }
};
