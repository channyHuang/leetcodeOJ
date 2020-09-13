class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int len = piles.size();
        sort(piles.begin(), piles.end());
        int stPos = 0, endPos = len - 1;
        int res = 0;
        while (stPos < endPos) {
            res += piles[endPos - 1];
            stPos++;
            endPos -= 2;
        }
        return res;
    }
};
