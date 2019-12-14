class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int res = 1;
        set<int> sister;
        int len = candies.size();
        int half = len / 2;
        if (len == 0) return 0;
        for (int i = 0; i < len; i++) {
            sister.insert(candies[i]);
            if (sister.size() >= half) return half;
        }
        return sister.size();
    }
};
