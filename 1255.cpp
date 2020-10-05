class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        len = words.size();
        count.resize(26, 0);
        counts.resize(len, vector<int>(26, 0));
        scores.resize(len, 0);
        for (int i = 0; i < letters.size(); i++) {
            count[letters[i] - 'a']++;
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                counts[i][words[i][j] - 'a']++;
                scores[i] += score[words[i][j] - 'a'];
            }
        }
        vector<int> curCounts(26, 0);
        search(words, 0, 0, curCounts);
        return res;
    }

    void search(vector<string>& words, int curIdx, int curScore, vector<int>& curCounts) {
        if (curIdx >= len) {
            res = max(curScore, res);
            return;

