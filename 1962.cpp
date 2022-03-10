class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int len = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());
        
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += piles[i];
        }
        if (k <= 0) return sum;
        while (k--) {
            if (piles[0] <= 1) break;
            sum -= (piles[0] >> 1);
            piles[0] -= (piles[0] >> 1);

            int index = 0;
            int nextindex = (index << 1) + 1;
            while (nextindex < len) {
                if (nextindex + 1 < len) {
                    int minidx = (piles[nextindex] <= piles[nextindex + 1] ? nextindex : nextindex + 1);
                    int maxidx = (piles[nextindex] > piles[nextindex + 1] ? nextindex : nextindex + 1);
                    if (piles[index] >= piles[maxidx]) {
                        break;
                    }
                    int tmp = piles[index];
                    piles[index] = piles[maxidx];
                    piles[maxidx] = tmp;
                    index = maxidx;
                } else {
                    if (piles[index] >= piles[nextindex]) break;
                    int tmp = piles[index];
                    piles[index] = piles[nextindex];
                    piles[nextindex] = tmp;
                    index = nextindex;
                }
                
                nextindex = (index << 1) + 1;
            }
        }
        return sum;
    }
};
