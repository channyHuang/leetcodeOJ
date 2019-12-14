class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int len = chars.length();
        int count[26] = {0};
        for (int i = 0; i < len; i++) {
            count[chars[i] - 'a']++;
        }
        len = words.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            int wordcount[26];
            memset(wordcount, 0, sizeof(wordcount));
            bool flag = true;
            for (int j = 0; j < words[i].length(); j++) {
                wordcount[words[i][j] - 'a']++;
                if (wordcount[words[i][j] - 'a'] > count[words[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) res += words[i].length();
        }
        return res;
    }
};
