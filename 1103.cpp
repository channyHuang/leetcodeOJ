class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res;
        res.resize(num_people);
        int n = 1, pos = 0;
        while (candies >= n) {
            res[pos++] += n;
            if (pos >= num_people) pos -= num_people;
            candies -= n;
            n++;
        }
        if (candies == 0) return res;
        res[pos] += candies;
        return res;
    }
};
