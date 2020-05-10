class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        int maxn = candies[0];
        for (int i = 1; i < len; i++) {
            maxn = max(maxn, candies[i]);
        }
        vector<bool> res(len, false);
        for (int i = 0; i < len; i++) {
            if (candies[i] + extraCandies >= maxn) res[i] = true;
        }
        return res;
    }
};
