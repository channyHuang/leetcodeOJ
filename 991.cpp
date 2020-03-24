class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        if (Y == 2) return 1;
        if (Y == 3) return Y - X + 1;
        if (Y == 4) return (X == 3 ? 3 : 2);

        long long level = 0;
        long long ly = Y;
        while (ly > X) {
            level++;
            if (ly & 1) ly++;
            else ly >>= 1;
        }

        return level + X - ly;
    }
};
