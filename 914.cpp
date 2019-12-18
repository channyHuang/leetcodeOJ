class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        if (len <= 1) return false;
        if (len == 2) return deck[0] == deck[1];

        int count[10001] = {0};
        for (int i = 0; i < len; i++) {
            count[deck[i]]++;
        }
        int maxfac = 0;
        for (int i = 0; i < 10001; i++) {
            if (count[i] == 0) continue;
            if (maxfac == 0) maxfac = count[i];
            else {
                maxfac = maxfactor(maxfac, count[i]);
            }
            if (maxfac <= 1) break;
        }
        if (maxfac <= 1) return false;
        return true;
    }

    int maxfactor(int x, int y) {
        if (x == y) return x;
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        while (x) {
            y %= x;
            int tmp = x;
            x = y;
            y = tmp;
        }
        return y;
    }
};
