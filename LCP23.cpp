class Solution {
public:
    bool isMagic(vector<int>& target) {
        int len = target.size();
        vector<vector<int>> card(2, vector<int>(len, 0));
        vector<int> cardlen(2, 0);
        for (int i = 0; i < len; i++) {
            card[0][i] = i + 1;
            if ((i & 1) == 1) card[1][cardlen[1]++] = i + 1;
        }
        for (int i = 0; i < len; i += 2) {
            card[1][cardlen[1]++] = i + 1;
        }
        int k = 0;
        while (k < len && card[1][k] == target[k]) k++;
        if (k == 0) return false;
        if (k >= len) return true;
        int pos = 1;
        int post = k;
        cardlen[1] = len;
        while (1) {
            for (int i = k + 1; i < cardlen[pos]; i += 2) {
                card[1 - pos][cardlen[1 - pos]++] = card[pos][i];
            }
            for (int i = k; i < cardlen[pos]; i += 2) {
                card[1 - pos][cardlen[1 - pos]++] = card[pos][i];
            }

            /*for (int i = 0; i < cardlen[1 - pos]; i++) {
                cout << card[1 - pos][i] << " ";
            }
            cout << endl;*/

            for (int i = 0; i < min(k, cardlen[1 - pos]); i++) {
                if (target[post] != card[1 - pos][i]) return false;
                post++;
            }
            //cardlen[1 - pos] -= k;
            if (cardlen[1 - pos] <= 0) return true;
            cardlen[pos] = 0;
            pos = 1 - pos;
        }
        return true;
    }
};
