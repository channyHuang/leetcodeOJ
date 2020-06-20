class Solution {
public:
    string smallestSubsequence(string text) {
        int len = text.length();
        string res = text;
        int pos = 0;
        int count[26] = {0};
        for (int i = 0; i < len; i++) {
            count[text[i] - 'a']++;
        }
        bool used[26] = {false};
        for (int i = 0; i < len; i++) {
            if (pos == 0) {
                res[pos++] = text[i];
                used[text[i] - 'a'] = true;
                continue;
            }
            if (used[text[i] - 'a']) {
                count[text[i] - 'a']--;
                continue;
            }
            if (count[res[pos - 1] - 'a'] > 1 && res[pos - 1] > text[i]) {
                count[res[pos - 1] - 'a']--;
                used[res[pos - 1] - 'a'] = false;
                pos--;
                i--;
                continue;
            }
            res[pos++] = text[i];
            used[text[i] - 'a'] = true;
        }
        res[pos] = 0;
        return res;
    }
};

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
