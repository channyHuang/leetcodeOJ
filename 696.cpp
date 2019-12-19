class Solution {
public:
    int countBinarySubstrings(string s) {
        int pos = 0, len = s.length();
        int count[2] = {0};
        int countIdx = 0, idx = 1;
        count[0] = 1;
        int res = 0;
        if (len <= 0) return 0;
        while(idx < len && s[idx] == s[pos]) {
            count[countIdx]++;
            idx++;
        }
        if (idx >= len) return res;
        countIdx = 1 - countIdx;
        pos = idx;
        while(idx < len && s[idx] == s[pos]) {
            count[countIdx]++;
            idx++;
        }
        pos = idx;
        
        while (idx < len) {
            res += min(count[0], count[1]);
            count[0] = count[1];
            count[1] = 0;
            while(idx < len && s[idx] == s[pos]) {
                count[1]++;
                idx++;
            }
            pos = idx;
        }
        res += min(count[0], count[1]);
        return res;
    }
};
