class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int len = stones.size();
        int count[3] = {0};
        for (int i = 0; i < len; ++i) {
            int tmp = stones[i] % 3;
            count[tmp]++;
        }
        bool bchange = (count[0] & 1);
        if (bchange) {
            return std::abs(count[1] - count[2]) > 2;
        } else {
            return (count[1] >= 1 && count[2] >= 1);
        }
    }
};
