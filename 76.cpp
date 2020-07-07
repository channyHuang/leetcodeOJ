class Solution {
public:
    string minWindow(string s, string t) {
        int stPos = 0;
        int maxLen = -1;
        //init needMap
        for (int i = 0; i < t.length(); i++) {
            needitr = needMap.find(t[i]);
            if (needitr == needMap.end()) {
                needMap.insert(pair<char, int>(t[i], 1));
            } else needitr->second++;
        }

        map<char, int> maps;
        map<char, int>::iterator itr;
        int i = 0;
        for (; i < s.length(); i++) {
            itr = maps.find(s[i]);
            if (itr == maps.end()) {
                maps.insert(pair<char, int>(s[i], 1));
            } else itr->second++;
            if (i < t.length() - 1) continue;

            if (valid(maps)) {
                maxLen = i + 1;
                break;
            }
        }
        if (maxLen == -1) return "";
        int pos = stPos;
        while(pos < s.length()) {
            itr = maps.find(s[pos]);
            itr->second--;
            pos++;

            bool found = true;
            while (!valid(maps)) {
                ++i;
                if (i >= s.length()) {
                    found = false;
                    break;
                }

                itr = maps.find(s[i]);
                if (itr == maps.end()) {
                    maps.insert(pair<char, int>(s[i], 1));
                } else itr->second++;
            }

            if (!found) break;
            if (maxLen > i - pos + 1) {
                stPos = pos;
                maxLen = i - pos + 1;
            }

        }
        return s.substr(stPos, maxLen);
    }

    bool valid(map<char, int>& maps) {
        for (needitr = needMap.begin(); needitr != needMap.end(); needitr++) {
            map<char, int>::iterator itr = maps.find(needitr->first);
            if (itr == maps.end() || itr->second < needitr->second) return false;
        }
        return true;
    }

private:
    map<char, int> needMap;
    map<char, int>::iterator needitr;
};
