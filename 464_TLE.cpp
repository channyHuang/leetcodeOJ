class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) return true;
        if (desiredTotal > (1 + maxChoosableInteger) * maxChoosableInteger / 2) return false;
        return can(maxChoosableInteger, 0, 0, desiredTotal);
    }

    bool can(int maxChoosableInteger, int status, int desired, int desiredTotal) {

        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (status & (1 << i) == (i << i)) continue;
            if (desired + i >= desiredTotal) return true;
            int newStatus = status | (1 << i);
            if ( !can(maxChoosableInteger, newStatus, desired + i, desiredTotal)) return true;
        }
        return false;
    }
};
