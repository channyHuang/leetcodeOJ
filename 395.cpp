class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.length();
        if (len < k) return 0;
        if (k <= 1) return len;        
        int res = 0;
        int count[26] = {0};
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
        }
        return longest(s, 0, len, k, count);
    }

    int longest(string s, int stPos, int endPos, int k, int count[26]) {
        if (endPos - stPos < k) return 0;
        if (k <= 1) return endPos - stPos;     
        int pos = stPos;
        int nextPos = stPos;
        int newCount[26];
        int res = 0;
        while (pos < endPos) {
            while (pos < endPos && count[s[pos] - 'a'] < k) pos++;
            nextPos = pos;
            memset(newCount, 0, sizeof(newCount));
            while (nextPos < endPos && count[s[nextPos] - 'a'] >= k) {
                newCount[s[nextPos] - 'a']++;
                nextPos++;
            }
            if (pos == stPos && nextPos >= endPos) res = max(res, endPos - stPos);
            else res = max(res, longest(s, pos, nextPos, k, newCount));
            
            pos = nextPos;
        }
        return res;
    }
};
