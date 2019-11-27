// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int stPos = 1, endPos = n;
        while (stPos <= endPos) {
            int midPos = stPos / 2 + endPos / 2;
            if (stPos % 2 && endPos % 2) midPos++; 
            int res = guess(midPos);
            if (res == 0) return midPos;
            else if (res == 1) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return 0;
    }
};
