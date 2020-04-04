/*这种贪心不行WA
class Solution {
public:
    string smallestSubsequence(string text) {
        int len = text.size();
        int count[26];
        for (int i = 0; i < 26; i++) {
            count[i] = -1;
        }
        string res = text;
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (count[text[i] - 'a'] == -1) {
                count[text[i] - 'a'] = pos;
                res[pos++] = text[i];
            } else if (count[text[i] - 'a'] == pos - 1) {
                continue;
            } else {
                int nextIdx = count[text[i] - 'a'] + 1;
                while (nextIdx < pos && res[nextIdx] == ' ') nextIdx++;
                if (nextIdx == pos) continue;
                if (res[count[text[i] - 'a']] < res[nextIdx]) continue;
                res[count[text[i] - 'a']] = ' ';
                count[text[i] - 'a'] = pos;
                res[pos++] = text[i];
            }
        }
        len = pos;
        pos = 0;
        for (int i = 0; i < len; i++) {
            if (res[i] == ' ') continue;
            res[pos++] = res[i];
        }
        res[pos] = 0;
        return res;
    }
};
*/
