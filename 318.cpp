class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        int len = words.size();
        if (len <= 0) return 0;
        int bits[len];
        memset(bits, 0, sizeof(bits));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                bits[i] |= (1 << (words[i][j] - 'a'));
            }
            for (int j = 0; j < i; j++) {
                if (words[i].length() * words[j].length() < res) continue;
                if (bits[i] & bits[j]) continue;
                res = words[i].length() * words[j].length();
            }
        }
        return res;
    }
};
