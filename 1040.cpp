class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int len = stones.size();
        vector<int> res;
        res.resize(2);
        //len >= 3
        sort(stones.begin(), stones.end());
        //max
        res[1] = max(stones[len - 2] - stones[0] - (len - 2), stones[len - 1] - stones[1] - (len - 2));
        if (stones[len - 1] - stones[0] == len - 1) return res;
        if (stones[len - 2] - stones[0] == len - 2) {
            res[0] = (stones[len - 1] - stones[len - 2] == 2 ? 1 : 2);
            return res;
        }
        if (stones[len - 1] - stones[1] == len - 2) {
            res[0] = (stones[1] - stones[0] == 2 ? 1 : 2);
            return res;
        }
        
        for (int i = 0; i < len; i++) {
            int stPos = stones[i];
            int endPos = stones[i] + len - 1;
            int has = 1;
            for (int j = i + 1; j < len; j++) {
                if (stones[j] <= endPos) has++;
                else break;
            }
            if (res[0] == 0) res[0] = len - has;
            else if (res[0] > len - has) res[0] = len - has;
        }
        return res;
    }
};
