class Solution {
public:
    bool canTransform(string start, string end) {
        int stlen = start.length();
        int endlen = end.length();
        int pos = 0;
        while (pos < endlen && end[pos] == 'X') pos++;
        int i;
        for (i = 0; i < stlen; i++) {
            if (start[i] == 'X') continue;
            if (pos >= endlen) return false;
            if (start[i] == end[pos]) {
                if (start[i] == 'L' && i < pos) return false;
                if (start[i] == 'R' && i > pos) return false;
                pos++;
                while (pos < endlen && end[pos] == 'X') pos++;
            } else return false;
        }
        if (pos != endlen) return false;
        return true;
    }
};
