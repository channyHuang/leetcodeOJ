class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> index;
        vector<int> res;
        res.resize(S.length());
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) index.push_back(i);
        }
        int pos = 0;
        for (int i = 0; i <= index[0]; i++) {
            res[i] = index[0] - i;
        }
        for (int i = S.length() - 1; i >= index[index.size() - 1]; i--) {
            res[i] = i - index[index.size() - 1];
        }
        if (index.size() >= 2) {
            for (int i = 0; i < index.size() - 1; i++) {
                for (int j = index[i] + 1; j <= index[i + 1]; j++) {
                    res[j] = min(j - index[i], index[i + 1] - j);
                }
            }
        }
        return res;
    }
};
