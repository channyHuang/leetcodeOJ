class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len = coordinates.size();
        if (len <= 1) return true;
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < len; i++) {
                if (coordinates[i][0] != coordinates[0][0]) return false;
            }
            return true;
        }
        if (coordinates[0][1] == coordinates[1][1]) {
            for (int i = 2; i < len; i++) {
                if (coordinates[i][1] != coordinates[0][1]) return false;
            }
            return true;
        }
        for (int i = 2; i < len; i++) {
            if ((coordinates[i][1] - coordinates[0][1]) * (coordinates[1][0] - coordinates[0][0]) != (coordinates[i][0] - coordinates[0][0]) * (coordinates[1][1] - coordinates[0][1])) return false;
        }
        return true;
    }
};
