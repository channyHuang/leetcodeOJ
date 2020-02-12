class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        res.clear();
        vector<int> index;
        search(index, s, 0);
        return res;
    }

    void search(vector<int> &index, string s, int stPos) {
        int len = s.length();
        if (stPos >= len) {
            vector<string> subres;
            for (int i = 0; i < index.size(); i++) {
                int x;
                if (i == 0) x = 0;
                else x = index[i - 1] + 1;
                subres.push_back(s.substr(x, index[i] - x + 1));
            }
            res.push_back(subres);
            return;
        }
        for (int endPos = stPos; endPos < len; endPos++) {
            if (valid(s, stPos, endPos)) {
                index.push_back(endPos);
                search(index, s, endPos + 1);
                index.pop_back();
            }
        }
    }

    bool valid(string s, int stPos, int endPos) {
        while (stPos < endPos) {
            if (s[stPos] != s[endPos]) return false;
            stPos++;
            endPos--;
        }
        return true;
    }
};