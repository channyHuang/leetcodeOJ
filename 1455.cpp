class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int lens = sentence.length();
        int lenw = searchWord.length();
        int pos = 0;
        int res = 1;
        int i = 0;
        while (i < lens && sentence[i] == ' ') i++;
        for (; i < lens; i++) {
            if (sentence[i] == ' ') {
                pos = 0;
                res++;
                continue;
            }
            if (sentence[i] != searchWord[pos]) {
                pos = 0;
                res++;
                while (i < lens && sentence[i] != ' ') i++;
            } else {
                pos++;
                if (pos == lenw) return res;
            }
        }
        return -1;
    }
};
