class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        if (cheeseSlices * 2 > tomatoSlices) return res;
        if (tomatoSlices & 1 == 1) return res;
        int left = (tomatoSlices - cheeseSlices * 2) / 2;
        if (left > cheeseSlices) return res;
        res.push_back(left);
        res.push_back(cheeseSlices - left);
        return res;
    }
};