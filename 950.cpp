class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int len = deck.size();
        if (len <= 2) return deck;
        vector<int> res;
        res.resize(len);
        int pos = 0;
        int i = 0;
        for (i = 0; i < len; i += 2) {
            res[i] = deck[pos++];
        }
        i = pos;
        if (len & 1) pos = len - 1;
        else pos = len - 2;
        for (; i < len; i++) {
            while (res[pos] != 0) {
                pos++;
                if (pos >= len) pos = 0;
            }
            pos++;
            if (pos >= len) pos = 0;
            while (res[pos] != 0) {
                pos++;
                if (pos >= len) pos = 0;
            }
            res[pos] = deck[i];
        }
        return res;
    }
};