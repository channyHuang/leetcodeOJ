class Solution {
public:
    int findTheLongestSubstring(string s) {
        int len = s.length();
        map<int, vector<int>> maps;
        map<int, vector<int>>::iterator itr;
        int code = 0;
        int res = 0;
        maps[0] = vector<int>(1, -1);
        for (int i = 0; i < len; i++) {
            int idx = targetIdx(s[i]);
            if (idx != -1) code ^= (1 << idx);
            itr = maps.find(code);
            if (itr == maps.end()) {
                vector<int> vec(1, i);
                maps.insert(pair<int, vector<int>>(code, vec));
            } else if (itr->second.size() == 1) {
                itr->second.push_back(i);
                res = max(res, itr->second[1] - itr->second[0]);
            } else {
                itr->second[1] = i;
                res = max(res, itr->second[1] - itr->second[0]);
            }
        }
        if (code == 0) return len;
        return res;
    }

    int targetIdx(char c) {
        switch (c) {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;
        default:
            break;
        }
        return -1;
    }
};
