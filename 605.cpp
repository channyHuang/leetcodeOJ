class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int stPos = 0;
        int res = 0;
        while (stPos < len) {
            if (flowerbed[stPos] == 0) stPos++;
            else break;
        }
        if (stPos >= len) {
            res = len / 2 + len % 2;
            return res >= n;
        }
        res = stPos / 2;
        if (res >= n) return true;
        for (int i = stPos + 1; i < len; i++) {
            if (flowerbed[i] == 0) continue;
            int tmp = i - stPos - 2;
            if (tmp <= 0) {
                stPos = i;
                continue;
            }
            res += tmp / 2;
            if (res >= n) return true;
            stPos = i;
        }
        res += (len - stPos - 1) / 2; 
        if (res >= n) return true;
        else return false;
    }
};
