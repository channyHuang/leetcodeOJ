class Solution {
public:
    int lastRemaining(int n) {
        int count = n;
        int diff = 1;
        int curSt = 1;
        bool left = true;
        while (count > 1) {
            if (left) {
                curSt += diff;             
            } else {
                if (count & 1) curSt += diff;
            }
            diff <<= 1;
            left = !left;
            count /= 2;
        }
        return curSt;
    }
};
