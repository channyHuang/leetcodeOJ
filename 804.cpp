class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int len = words.size();
        int res = 0;
        map<string, int> wordcodes;
        for (int i = 0; i < len; i++) {
            int lenw = words[i].length();
            string str;
            for (int j = 0; j < lenw; j++) {
                str += codes[words[i][j] - 'a'];
            }
            if (wordcodes.find(str) == wordcodes.end()) wordcodes.insert(pair<string, int>(str, 1));
        }
        res = wordcodes.size();
        return res;
    }
};
