class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int index[26] = {0};
        for (int i = 0; i < order.length(); i++) {
            index[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            if (!bigger(words[i - 1], words[i], index)) return false;
        }
        return true;
    }

    bool bigger(string a, string b, int index[]) {
        int lenb = b.length();
        int i;
        for (i = 0; i < lenb; i++) {
            if (index[b[i] - 'a'] > index[a[i] - 'a']) return true;
            else if (index[b[i] - 'a'] < index[a[i] - 'a']) return false;
            if (a[i] == 0) break;
        }
        if (a[i] != 0) return false;
        return true;
    }
};
