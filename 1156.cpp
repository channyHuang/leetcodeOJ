class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<int, int>> vec[26];
        int stPos = 0;
        int endPos = 0;
        for (int i = 1; i < text.length(); i++) {
            if (text[i] == text[stPos]) {
                endPos = i;
                continue;
            }
            vec[text[stPos] - 'a'].push_back(pair<int, int>(stPos, endPos));
            stPos = i;
            endPos = i;
        }
        vec[text[stPos] - 'a'].push_back(pair<int, int>(stPos, endPos));
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (vec[i].size() == 0) continue;
            if (vec[i].size() == 1) {
                res = max(res, vec[i][0].second - vec[i][0].first + 1);
                continue;
            }
            res = max(res, vec[i][0].second - vec[i][0].first + 1 + 1);
            for (int j = 1; j < vec[i].size(); j++) {
                res = max(res, vec[i][j].second - vec[i][j].first + 1 + 1);
                if (vec[i][j].first - vec[i][j - 1].second != 2) continue;
                if (vec[i].size() == 2) {
                    res = max(res, vec[i][j].second - vec[i][j].first + 1 + vec[i][j - 1].second - vec[i][j - 1].first + 1);
                } else {
                    res = max(res, vec[i][j].second - vec[i][j].first + 1 + vec[i][j - 1].second - vec[i][j - 1].first + 1 + 1);
                }
            }
        }
        return res;
    }
};
