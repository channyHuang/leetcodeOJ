class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> index(26, vector<int>());
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int idx = s[i] - 'a';
            index[idx].push_back(i);
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (index[i].size() <= 1) continue;
            if (index[i].size() >= 3) res++;
            int stpos = index[i][0], endpos = index[i][index[i].size() - 1];
            for (int j = 0; j < 26; ++j) {
                if (j == i) continue;
                if (find(index[j], stpos, endpos)) res++;
            }      
        }
        return res;
    }

    bool find(vector<int> &idx, int stpos, int endpos) {
        int len = idx.size();
        if (len <= 0) return false;
        int stidx = 0, endidx = len - 1;
        while (stidx <= endidx) {
            int mididx = (stidx + endidx) / 2;
            if (idx[mididx] < stpos) stidx = mididx + 1;
            else if (idx[mididx] > endpos) endidx = mididx - 1;
            else return true;
        }
        return false;
    }
};

