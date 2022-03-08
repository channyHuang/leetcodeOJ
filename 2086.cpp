class Solution {
public:
    int minimumBuckets(string street) {
        int len = street.length();
        int res = 0;
        int lastpos = -1;
        for (int i = 0; i < len; ++i) {
            if (street[i] == '.') continue;
            if (i == 0) {
                if (i == len - 1 || street[i + 1] != '.') return -1;
                lastpos = i + 1;
                res++;
                i++;
                continue;
            }
            if (i == len - 1) {
                if (lastpos == i - 1) break;
                if (street[i - 1] != '.') return -1;
                res++;
                lastpos = i - 1;
                break;
            }
            if (lastpos == i - 1) continue;
            if (street[i + 1] == '.') {
                lastpos = i + 1;
                res++;
            } else if (street[i - 1] == '.') {
                lastpos = i - 1;
                res++;
            } else return -1;
        }
        return res;
    }
};
