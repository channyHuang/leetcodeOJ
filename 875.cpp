class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int len = piles.size();
        sort(piles.begin(), piles.end());
        if (len == 1) return piles[0] / H + (piles[0] % H == 0 ? 0 : 1);
        int stPos = 1, endPos = piles[len - 1];
        int res = piles[len - 1];
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            int times = 0;
            for (int i = 0; i < len; i++) {
                times += (piles[i] / midPos) + (piles[i] % midPos == 0 ? 0 : 1);
                if (times > H) break;
            }
            if (times > H) {
                stPos = midPos + 1;
            } else {
                res = midPos;
                endPos = midPos - 1;
            }
        }
        return res;
    }
};
