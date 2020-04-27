class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int maxn = 0;
        int count[5] = {0};
        int len = croakOfFrogs.length();
        for (int i = 0; i < len; i++) {
            int idx = index(croakOfFrogs[i]);
            if (idx == -1) return idx;
            count[idx]++;
            if (idx > 0 && count[idx] > count[idx - 1]) return -1;
            if (idx == 0) maxn = max(maxn, count[idx]);
            if (idx == 4) {
                for (int j = 0; j < 5; j++) {
                    count[j]--;
                }
            }
        }
        for (int j = 0; j < 5; j++) {
            if (count[j] != 0) return -1;
        }
        return maxn;
    }

    int index(char c) {
        if (c == 'c') return 0;
        if (c == 'r') return 1;
        if (c == 'o') return 2;
        if (c == 'a') return 3;
        if (c == 'k') return 4;
        return -1;
    }
};
