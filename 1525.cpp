class Solution {
public:
    int numSplits(string s) {
        int len = s.length();
        int res = 0;
        if (len <= 1) return 0;
        vector<pair<int, int>> vec;
        vector<bool> used(26, false);
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (!used[s[i] - 'a']) {
                used[s[i] - 'a'] = true;
                count++;
            }
            vec.push_back(make_pair(count, 0));
        }
        used.clear();
        used.resize(26, false);
        count = 0;
        for (int i = len - 1; i >= 0; i--) {
            vec[i].second = count;
            if (!used[s[i] - 'a']) {
                used[s[i] - 'a'] = true;
                count++;
            }
            if (vec[i].first == vec[i].second) res++;
        }
        return res;
    }
};
