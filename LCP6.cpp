class Solution {
public:
    int minCount(vector<int>& coins) {
        int len = coins.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            res += ((coins[i] >> 1) + (coins[i] & 1));
        }
        return res;
    }
};
