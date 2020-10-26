class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx == ty) {
            if (tx == sx && ty == sy) return true;
            return false;
        }
        if (tx < sx || ty < sy) return false;
        if (tx < ty) {
            if (tx == sx && (ty - sy) % tx == 0) return true;
            return reachingPoints(sx, sy, tx, ty % tx);
        } else {
            if (ty == sy && (tx - sx) % ty == 0) return true;
            return reachingPoints(sx, sy, tx % ty, ty);
        }
        return false;
    }
};
