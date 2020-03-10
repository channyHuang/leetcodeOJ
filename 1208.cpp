class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length();
        int cost[len] = {0};
        int minCost = 100;
        for (int i = 0; i < len; i++) {
            cost[i] = abs(s[i] - t[i]);
            if (cost[i] < minCost) minCost = cost[i];
        }
        if (minCost > maxCost) return 0;
        int maxlen = 2;
        int pos = 0;
        while (pos < len) {
            int curCost = 0;
            int i;
            int endPos = pos + maxlen;
            if (endPos > len) break;
            for (i = pos; i < endPos; i++) {
                curCost += cost[i];
                if (curCost > maxCost) break;
            }
            if (i < pos + maxlen) {
                pos++;
                continue;
            }
            maxlen++;
        }
        return maxlen - 1;
    }
};
