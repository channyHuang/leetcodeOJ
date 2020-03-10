class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        if (len <= 2) return true;
        int maxn[len][len] = {0};
        
        for (int i = 0; i < len - 1; i++) {
            maxn[i][i + 1] = abs(piles[i] - piles[i + 1]);
        }
        for (int d = 3; d < len; d += 2) {
            for (int i = 0; i < len; i++) {
                if (i + d >= len) break;
                maxn[i][i + d] = piles[i] - piles[i + 1] + maxn[i + 2][i + d];
                maxn[i][i + d] = max(maxn[i][i + d], piles[i] - piles[i + d] + maxn[i + 1][i + d - 1]);
                maxn[i][i + d] = max(maxn[i][i + d], piles[i + d] - piles[i + d - 1] + maxn[i][i + d - 2]);
                maxn[i][i + d] = max(maxn[i][i + d], piles[i + d] - piles[i] + maxn[i][i + d - 1]);
            }
        }
        return maxn[0][len - 1] > 0 ? true : false;
    }
};
