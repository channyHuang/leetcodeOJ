class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num <= 1) return true;
        int stPos = 2, endPos = 46340;
        while (stPos <= endPos) {
            int mid = (stPos + endPos) / 2;
            if (mid * mid > num) endPos = mid - 1;
            else if (mid * mid == num) return true;
            else stPos = mid + 1;
        }
        //for (int i = 2; i <= 46340; i++) {
        //    if (num == i * i) return true;
        //}
        return false;
    }
};
