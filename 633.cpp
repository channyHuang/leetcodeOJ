class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c <= 1) return true;
        int sum[46341] = {0};
        for (int i = 0; i <= 46340; i++) {
            sum[i] = i * i;
        }
        int stPos = 0, endPos = 46340; 
        while (stPos <= endPos) {
            while (sum[endPos] > c) endPos--;
            if (sum[stPos] > c - sum[endPos]) endPos--;
            else if (sum[stPos] + sum[endPos] == c) return true;
            else stPos++;
        }
        return false;
    }
};
