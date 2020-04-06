class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if (S.length() <= 0) return words.size();
        vector<char> vecS;
        vector<int> cntS;
        vecS.push_back(S[0]);
        cntS.push_back(1);
        int pos = 1;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == vecS[pos - 1]) cntS[pos - 1]++;
            else {
                vecS.push_back(S[i]);
                cntS.push_back(1);
                pos++;
            }
        }
        int len = pos;
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].length() <= 0 || words[i][0] != vecS[0]) continue;
            vector<char> vecW;
            vector<int> cntW;
            cntW.push_back(1);
            int pos = 1;
            int j;
            for (j = 1; j < words[i].length(); j++) {
                if (words[i][j] == vecS[pos - 1]) {
                    cntW[pos - 1]++;
                    if (cntW[pos - 1] > cntS[pos - 1]) break;
                } else {
                    if (cntW[pos - 1] <= 0) break;
                    if (cntS[pos - 1] == 2 && cntW[pos - 1] == 1) break;
                    if (vecS[pos] != words[i][j]) break;
                    pos++;
                    cntW.push_back(1);
                }
            }
            if (j < words[i].length()) continue;
            if (cntS[pos - 1] == 2 && cntW[pos - 1] == 1) continue;
            if (pos != len) continue;
            res++;
        }
        return res;
    }
};
