class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();
        if (len <= 0) return 0;
        if (len <= 1) return stones[0];
        while (1) {
            sort(stones.begin(), stones.end());
            if (stones[len - 2] == 0) return stones[len - 1];
            stones[len - 1] -= stones[len - 2];
            stones[len - 2] = 0;           
        }
        return stones[len - 1];
    }
};
