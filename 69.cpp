class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        else if (x <= 3) return 1;
        return find(2, x / 2, x);
    }

    int find(int stPos, int endPos, int x) {
        if (stPos >= endPos) return stPos;
        if (endPos - stPos == 1) {
            if (x / endPos == endPos) return endPos;
            return stPos;
        };
        int midPos = (stPos + endPos) / 2;
        int factor = x / midPos;
        if (factor <= midPos) return find(stPos, midPos, x);
        else return find(midPos, endPos, x);
    }
};
