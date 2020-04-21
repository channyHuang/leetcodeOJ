class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int len = tokens.size();
        if (len <= 0) return 0;
        sort(tokens.begin(), tokens.end());
        if (P < tokens[0]) return 0;
        int stPos = 0;
        int endPos = len - 1;
        int score = 0;
        int res = 0;
        while (stPos <= endPos) {
            while (stPos <= endPos && P >= tokens[stPos]) {
                score++;
                P -= tokens[stPos];
                stPos++;
                res = max(res, score);
            }
            if (stPos <= endPos && score > 0) {
                score--;
                P += tokens[endPos];
                endPos--;
            }
        }
        return res;
    }
};
