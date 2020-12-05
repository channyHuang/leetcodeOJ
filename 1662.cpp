class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len2 == 0) {
            return (len1 == 0);
        }
        int pos1 = 0, pos2 = 0;
        int j = 0;
        for (int i = 0; i < len1; i++) {
            while (pos1 < word1[i].length()) {                
                while (j < word2.size() && pos2 >= word2[j].length()) {
                    j++;
                    pos2 = 0;
                }
                if (j >= word2.size()) return false;
                if (word1[i][pos1] != word2[j][pos2]) return false;
                pos2++;
                pos1++;
            }
            pos1 = 0;
        }
        if (pos2 < word2[j].length() || j != word2.size() - 1) return false;
        return true;
    }
};
