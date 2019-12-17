class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> sets;
        int index = -1;
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].length();
            if (len == 1) {
                sets.insert(words[i]);
                if (index == -1) index = i;
            } else {
                if (sets.find(words[i].substr(0, len - 1)) != sets.end()) {
                    sets.insert(words[i]);
                    if (words[index].length() < len) index = i;
                }
            }
        }
        if (index == -1) return "";
        return words[index];
    }
};
