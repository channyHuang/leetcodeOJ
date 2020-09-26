class Solution {
public:
    int maxUniqueSplit(string s) {
        len = s.length();
        unordered_set<string> sets;
        search(s, 0, sets);
        return res;
    }

    void search(string& s, int stPos, unordered_set<string>& sets) {
        if (stPos >= len) {
            if (res < sets.size()) res = sets.size();
            return;
        }
        for (int i = stPos; i < len; i++) {
            if (sets.find(s.substr(stPos, i - stPos + 1)) != sets.end()) {
                continue;
            }
            sets.insert(s.substr(stPos, i - stPos + 1));
            search(s, i + 1, sets);
            sets.erase(s.substr(stPos, i - stPos + 1));
        }
    }

private:
    int res = 1;
    int len;
};
