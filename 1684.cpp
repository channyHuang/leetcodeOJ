class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int alen = allowed.length();
        int wlen = words.size();
        vector<bool> has(26, false);
        for (int i = 0; i < alen; i++) {
            has[allowed[i] - 'a'] = true;
        }
        int res = 0;
        for (int i = 0, j; i < wlen; i++) {
            for (j = 0; j < words[i].length(); j++) {
                if (has[words[i][j] - 'a'] == false) break;
            }
            if (j >= words[i].length()) {
                res++;
            }
        }
        return res;
    }
};