class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        set<pair<int, int>> sets;
        if (z == 0) return true;
        if (z > x + y) return false;
        if (x == y) return (z == x || z == x + y);
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        if (z == x || z == y) return true;
        int lefty = y - x;
        int leftx = 0;
        while (1) {
            if (lefty == z || leftx == z || leftx + lefty == z || leftx + y == z || lefty + x == z) return true;
            if (sets.find(pair<int, int>(lefty, leftx)) != sets.end()) return false;
            sets.insert(pair<int, int>(lefty, leftx));
            if (leftx + lefty >= x) {
                lefty -= (x - leftx);
                leftx = 0;
            } else {
                leftx += lefty;
                lefty = y;
            }
        }
        return false;
    }
};
